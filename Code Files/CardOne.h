#pragma once
#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardOne :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardOne(const CellPosition & pos); // A Constructor takes card position
	CardOne();

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                              
	virtual Card* Copy(); //To copy card and it's parameters in copy/cut

	virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);

	virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);
	
	virtual ~CardOne(); // A Virtual Destructor
};

