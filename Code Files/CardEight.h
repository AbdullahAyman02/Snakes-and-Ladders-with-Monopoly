#pragma once
#include "Card.h"

class CardEight :
    public Card
{
    int PrisonFee; // amount of coins to get out of prison
public:
    CardEight(const CellPosition& pos);
    CardEight();

    virtual void ReadCardParameters(Grid* pGrid); //Reads the parameters of CardEight which is : PrisonFee

    virtual Card* Copy(); //To copy card and it's parameters in copy/cut

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player

    virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);
    virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);
};
