#include "Player.h"

#include "GameObject.h"
#include "Card9_11.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(1), wallet(100), playerNum((playerNum >= 0 && playerNum < MaxPlayerCount) ? playerNum:0)
{
	this->pCell = pCell;
	this->turnCount = 0;
	// Make all the needed initialization or validations
	justRolledDiceNum = 0; 
	prisonCount = 0;
	extraDiceRoll = false;
	for (int i = 0; i < 3; i++)
		owned_stations[i] = NULL;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = (wallet > 0) ? wallet:0;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetPlayernum() const
{
	return playerNum;
}

void Player::SetPrisonCount(int prison)
{
	prisonCount = prison;
}
bool Player::InPrison() const
{
	return (prisonCount == 0) ? false : true;
}
void Player::DecrementPrisonCount()
{
	prisonCount = (prisonCount > 0) ? --prisonCount : 0;
}

void Player::IncrementTurnCount()
{
	turnCount++;
}

void Player::Setstationsowned(Card9_11& station)
{
	owned_stations[numofstationsowned] = &station;
	numofstationsowned++;
}

Card9_11* Player::GetStationsowned() const
{
	return *owned_stations;
}

int Player::GetNumofStationsowned() const
{
	return numofstationsowned;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetjustRolledDiceNum()
{
	return justRolledDiceNum;
}

void Player::setExtraDiceRoll(bool flag)
{
	extraDiceRoll = flag;
}

bool Player::getExtraDiceRoll() const
{
	return extraDiceRoll;
}

void Player::SetStepCount(int step)
{
	stepCount = step;
}

int Player::GetStepCount() const
{
	return stepCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	//IncrementTurnCount();
	turnCount++;
	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3)
	{
		turnCount = 0;
		wallet += (diceNumber > 0) ? (10 * diceNumber):0;
		DecrementPrisonCount(); //If Player in Prison
		return;
	}
	
	// 3- Set the justRolledDiceNum with the passed diceNumber
	
	if (wallet > 0 && prisonCount == 0 && diceNumber != -1 && diceNumber != 0)
	{
		justRolledDiceNum = diceNumber;
		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(diceNumber);

		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
		if ((this->GetStepCount() + diceNumber) > 99)
		{
			pGrid->PrintErrorMessage("You rolled " + to_string(diceNumber) + ". Cannot go out of grid. Click to continue...");
			diceNumber = 0;
			return;
		}
		pGrid->UpdatePlayerCell(this, pos);

		
		// 6- Apply() the game object of the reached cell (if any)
		//Apply Done in UpdatePlayerCell function in Grid
		// 
		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		if (pCell->GetCellPosition().GetCellNum() == 99)
			pGrid->SetEndGame(true);
	}
	else
		DecrementPrisonCount(); //If Player in Prison
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ", ";
	playersInfo += to_string(stepCount) + ")"; //Helpful in testing
}

void Player::DecrementWallet(int decrement)
{
	SetWallet(wallet - decrement);
}


Player* Player::Findnextplayer(Player* const* arrofplayers, int numofplayers)
{
	int stepcountofplayer, playernumofplayer, distbetplayers;
	int leastdistbetplayers = 99;
	Player* nextplayer;
	bool isplayernext = false;
	for (int i = 0; i < numofplayers; i++) {
		if (arrofplayers[i]->playerNum == playerNum) // checks if player from the array is same as the calling player
			continue;
		else {
			stepcountofplayer = arrofplayers[i]->GetStepCount(); // getting stepcount of player
			distbetplayers = stepcountofplayer - stepCount;
			if (distbetplayers < leastdistbetplayers && distbetplayers > 0) { // makes sure that the player is the one closest to the calling player
				leastdistbetplayers = distbetplayers; // sets the new least distance between the calling player and the next player
				nextplayer = arrofplayers[i];
				isplayernext = true;
			}
		}
	}
	if (isplayernext) // makes sure that there is actually a player after the calling player
		return nextplayer;
	else
		return NULL;
}

Player* Player::Findpoorestplayer(Player* const* arrofplayers, int numofplayers)
{
	int leastcoins = arrofplayers[0]->wallet; //getting wallet of the first player
	Player* poorestplayer = arrofplayers[0]; // initialising poorest player as the first player
	// finding poorest player among the players
	for (int i = 1; i < numofplayers; i++) {
		if (arrofplayers[i]->wallet < leastcoins) {
			leastcoins = arrofplayers[i]->wallet;
			poorestplayer = arrofplayers[i];
		}
	}
	return poorestplayer;
}

void Player::Transfermostexpensivestation(Player*& poorestplayer)
{
	if (numofstationsowned == 0) // checks if player has no stations
		return;
	Card9_11* tempstation = owned_stations[0]; // initialising most exensive station as the first station
	int index = 0;
	// checks if there are other stations which are more expensive 
	for (int i = 1; i < numofstationsowned; i++) {
		if (owned_stations[i]->GetCardPrice() > tempstation->GetCardPrice()) {
			tempstation = owned_stations[i];
			index = i;
		}
	}
	owned_stations[index] = NULL; // removes the station from the calling player
	tempstation->Changeowners(poorestplayer);
	numofstationsowned--; // decrements the number of stations owned by the calling player
	poorestplayer->Setstationsowned(*tempstation); // transfers the most expensive station to the poorest player
}

void Player::Transfercoins(Player* debtor, int fee)
{
	if (fee <= debtor->GetWallet()) {
		wallet += fee;
		debtor->DecrementWallet(fee);
	}
	else {
		wallet += debtor->GetWallet();
		debtor->SetWallet(0);
	}
}
void Player::ResetPlayer()
{
	SetWallet(100);
	SetPrisonCount(0);
	turnCount = 0;
	justRolledDiceNum = 0;
	extraDiceRoll = false;

	if (numofstationsowned > 0)
	{
		for (int i = 0; i < numofstationsowned; i++)
		{
			owned_stations[i]->Resetowner();
			owned_stations[i] = NULL;
			numofstationsowned--;
		}
	}
}