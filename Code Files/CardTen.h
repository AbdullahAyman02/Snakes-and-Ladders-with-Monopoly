#pragma once
#include "Card9_11.h"
class CardTen :
    public Card9_11
{
    static int cardPrice10; // the price of the station(card)
    static int cardFee10; // the fee to be paid by the other players
    static Player* owner10; // pointer representing the owner of the station
    static bool isSaved;
    static bool isOpened;
public:
    CardTen(const CellPosition& pos); // A Constructor takes card position
    CardTen();

    void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTen which is : cardPrice10 and cardFee10

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player

    virtual Card* Copy(); //To copy card and it's parameters in copy/cut

    virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);


    virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

    virtual int GetCardPrice(); // A getter for card price

    virtual void Changeowners(Player* newowner); // changes the owner of the station

    virtual void Resetowner(); // Resets the owner of the station back to NULL

    ~CardTen(); // A Virtual Destructor
};
