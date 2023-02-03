#include "Card.h"
#include<fstream>
#include "DEFS.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"


Card::Card(const CellPosition & pos) : GameObject(pos), cardNumber(-1) // sets the cell position of the GameObject
{
	type = CARD;
}

Card::Card()
{
}

void Card::SetCardPosition(CellPosition& cardDestination)
{
	position = cardDestination;
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = (cnum > 0 && cnum <= 12) ? cnum : -1; // needs validation
}

int Card::GetCardNumber() const
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card* Card::Copy()
{
	return nullptr;
}

void Card::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//To save a card, we first write its number and position,this function will be called in each card type at the start of saving
	outFile << cardNumber << "     " << CellPosition::GetCellNumFromPosition(position) << "     ";
}

void Card::Open(ifstream& inFile, ObjectType& type, Grid* gPtr)
{
	//obtaining number of cards from file
	int cardNumber = 0;

	inFile >> cardNumber;
	//depending on the card number, create a card of given type(1,2,3,..) to call the function open.

	Card* currentCard;
	switch (cardNumber)
	{
	case 1: currentCard = new CardOne();

		currentCard->Open(inFile, type, gPtr);
		break;
	case 2: currentCard = new CardTwo();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 3: currentCard = new CardThree();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 4:currentCard = new CardFour();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 5:currentCard = new CardFive();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 6:currentCard = new CardSix();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 7:currentCard = new CardSeven();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 8:currentCard = new CardEight();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 9:currentCard = new CardNine();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 10:currentCard = new CardTen();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 11:currentCard = new CardEleven();
		currentCard->Open(inFile, type, gPtr);
		break;
	case 12:currentCard = new CardTwelve();
		currentCard->Open(inFile, type, gPtr);
		break;
	}
	gPtr->UpdateInterface();
}
Card::~Card()
{
}
