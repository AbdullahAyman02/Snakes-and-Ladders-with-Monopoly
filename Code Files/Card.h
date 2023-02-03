#pragma once

#include <fstream>
#include "DEFS.h"
#include "GameObject.h"
#include "Player.h"


// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
protected:
	int cardNumber; // an integer representing the card number

public:
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it
	Card(); //Default Constructor for calling open function of each GameObjectType (dummy object)->Same for all cards

	void SetCardPosition(CellPosition& cardDestination); //Used in Paste Card Action

	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber() const;            // The getter of card number

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	virtual void ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
	                                               // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	                                                   // It is a virtual function (implementation depends on Card Type)

	virtual Card* Copy(); //To copy card and it's parameters in copy/cut

	virtual void Save(ofstream& outFile, ObjectType& type, int& cellNum);

	virtual void Open(ifstream& inFile, ObjectType& type, Grid* gPtr);

	virtual ~Card(); // A Virtual Destructor
};

