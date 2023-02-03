#pragma once
#include "Card.h"
class Player;
class Card9_11 :
    public Card
{
public:
    Card9_11(const CellPosition& pos); // A Constructor takes card position
    Card9_11();

    virtual void ReadCardParameters(Grid* pGrid, int &cp,int &cf); // Reads the parameters

    virtual void Apply(Grid* pGrid, Player* pPlayer,int &cp,int &cf,Player*& pl); // Applies the effect

    virtual int GetCardPrice() = 0; // A getter card price

    virtual void Changeowners(Player* newowner) = 0; // changes the owner of the station

    virtual void Resetowner() = 0; // Resets the owner of the station back to NULL

    virtual ~Card9_11(); // A Virtual Destructor
};
