#pragma once
#include "Card.h"

class CardFive : public Card
{

public:
	CardFive(const CellPosition& pos);
	CardFive();

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* Copy(); //To copy card and it's parameters in copy/cut

	virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);

	virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

	virtual ~CardFive();
};

