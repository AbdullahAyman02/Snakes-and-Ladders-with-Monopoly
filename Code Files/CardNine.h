#pragma once
#include "Card9_11.h"
class CardNine :
    public Card9_11
{
    static int cardPrice9; // the price of the station(card)
    static int cardFee9; // the fee to be paid by the other players
    static Player* owner9; // pointer representing the owner of the station
    static bool isSaved;//Checks wether the data members of card nine is saved
    static bool isOpened;
public:
    CardNine(const CellPosition& pos); // A Constructor takes card position
    CardNine();

    void ReadCardParameters(Grid* pGrid); // Applies the effect of CardNine on the passed Player

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player

    virtual Card* Copy(); //To copy card and it's parameters in copy/cut

    virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);


    virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);
    virtual int GetCardPrice();

    virtual void Changeowners(Player* newowner); // changes the owner of the station

    virtual void Resetowner(); // Resets the owner of the station back to NULL
    
    virtual ~CardNine(); // A Virtual Destructor
};
