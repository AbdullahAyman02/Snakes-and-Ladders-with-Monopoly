#pragma once
#include "Card.h"

class CardSix : public Card
{
	CellPosition destcell;
public:
	CardSix(const CellPosition& pos);
	CardSix();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is: Cell to move to

	virtual Card* Copy(); //To copy card and it's parameters in copy/cut

	virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);

	virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
													  // by moving the player to the destination cell

	virtual ~CardSix();
};
