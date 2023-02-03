#pragma once
#include "Card.h"

class CardTwo: public Card
{
public:
	CardTwo(const CellPosition& pos);
	CardTwo();

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* Copy(); //To copy card and it's parameters in copy/cut

	virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);
	virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

	virtual ~CardTwo();
};

