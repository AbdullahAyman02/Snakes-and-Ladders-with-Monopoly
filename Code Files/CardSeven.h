#pragma once
#include "Card.h"

class CardSeven :
    public Card
{
public:
    CardSeven(const CellPosition& pos);
    CardSeven();

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
    virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);

    virtual Card* Copy(); //To copy card and it's parameters in copy/cut

    virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

    virtual ~CardSeven();
};
