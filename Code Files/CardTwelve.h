#pragma once
#include "Card.h"
class CardTwelve :
    public Card
{
public:
    CardTwelve(const CellPosition& pos); // A Constructor takes card position
    CardTwelve();

    virtual void Apply(Grid* pGrid, Player* pPlayer); //Applies the effect of cardTwelve on the passed player

    virtual Card* Copy(); //To copy card and it's parameters in copy/cut

    virtual void CardTwelve::Open(ifstream& InFile, ObjectType& type, Grid* gPtr);



    virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

    virtual ~CardTwelve(); // A Virtual Destructor
};
