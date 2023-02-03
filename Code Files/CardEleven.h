#pragma once
#include "Card9_11.h"
class CardEleven :
    public Card9_11
{
    static int cardPrice11; // the price of the station(card)
    static int cardFee11; // the fee to be paid by the other players
    static Player* owner11; // pointer representing the owner of the station
    static bool isSaved;
    static bool isOpened;
public:
    CardEleven(const CellPosition& pos); // A Constructor takes card position
    CardEleven();

    void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven which is : cardPrice11 and cardFee11

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player

    virtual Card* Copy(); //To copy card and it's parameters in copy/cut

    virtual void Open(ifstream& InFile, ObjectType& type, Grid* gPtr);


    virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

    virtual int GetCardPrice();

    virtual void Changeowners(Player* newowner);

    void Resetowner();

    ~CardEleven(); // A Virtual Destructor
};
