#pragma once

#include "Grid.h"
#include "Cell.h"

class Card9_11;
class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	
	int prisonCount;		// a count that represents the count of the player if he is in prison (landed on card 8 and did not pay the fee)
	bool extraDiceRoll;		// if the player lands on card 3, he gets an extra dice roll

	Card9_11* owned_stations[3]; // an array of pointers representing stations owned by the player
	int numofstationsowned = 0; // number of stations owned

public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet
	int GetPlayernum() const;       // A getter for the player number

	int GetTurnCount() const;		// A getter for the turnCount
	int GetStepCount() const;		// A geeter for the stepCount
	void SetStepCount(int step);	// A setter for the stepCount

	void Setstationsowned(Card9_11& station); // A setter for the stations
	Card9_11* GetStationsowned() const; // A getter for the stations 
	int GetNumofStationsowned() const; // A getter for the number of stations owned by the player

	void SetPrisonCount(int prison = 3);
	bool InPrison() const;		// Boolean to check if player in prison or not for moving
	void DecrementPrisonCount();
	void IncrementTurnCount();	// Increments the turnCount

	int GetjustRolledDiceNum();	// To move backwards when a player reaches Card 5
	void setExtraDiceRoll(bool flag = true);	// To allow the player to get an extra dice roll
	bool getExtraDiceRoll() const;	// To print a message for the user if he gets an extra dice roll (used in RollDiceAction.cpp)

	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

	void DecrementWallet(int decrement); // Decrements wallet by amount specified in CardOne

	Player* Findnextplayer(Player* const* arrofplayers, int numofplayers); // finds the next player on the grid

	Player* Findpoorestplayer(Player* const* arrofplayers, int numofplayers); // finds the poorest player

	void Transfermostexpensivestation(Player*& pooresplayer); // transfers most expensive station to the poorest player

	void Transfercoins(Player* debtor, int fee); // transfers coins from player(debtor) to the calling player

	void ResetPlayer(); //Resets the data members of a player
};