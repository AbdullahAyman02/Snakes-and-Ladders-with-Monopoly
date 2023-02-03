#pragma once
#include "Card.h"

class CardFour : public Card
{
public:
	
	CardFour(const CellPosition& pos);
	CardFour();

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* Copy(); //To copy card and it's parameters in copy/cut

	virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);

	virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

	virtual ~CardFour();
};

