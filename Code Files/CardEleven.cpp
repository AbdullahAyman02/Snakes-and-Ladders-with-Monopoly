#include "CardEleven.h"

int CardEleven::cardPrice11 = -1;
int CardEleven::cardFee11 = -1;
Player* CardEleven::owner11 = NULL;
bool CardEleven::isSaved = false;
bool CardEleven::isOpened = false;

CardEleven::CardEleven(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 11; // setting the inherited cardNumber data member with the card number (11 here)
}

CardEleven::CardEleven()
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardEleven...");
	Card9_11::ReadCardParameters(pGrid, cardPrice11, cardFee11);
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer, cardPrice11, cardFee11, owner11);
}

Card* CardEleven::Copy()
{
	Card* temp = new CardEleven(this->GetPosition());
	*temp = *this;
	return temp;
}

int CardEleven::GetCardPrice()
{
	return cardPrice11;
}

void CardEleven::Changeowners(Player* newowner)
{
	owner11 = newowner;
}

void CardEleven::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//If the card parameter was already written, do not write it again
	//firstly saving cardnumber and position
	Card::Save(outFile, type, cellNum);
	if (!isSaved)
	{
		//secondly writing the cardParameters
		outFile << cardPrice11 << "     " << cardFee11 << endl;
		isSaved = true;
	}
	else
	{
		outFile << endl;
	}
}

void CardEleven::Resetowner()
{
	owner11 = NULL;
}

void CardEleven::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	int cPos;

	InFile >> cPos;

	CardEleven* cPtr = new CardEleven(CellPosition::GetCellPositionFromNum(cPos));

	if (!isOpened)
	{
		InFile >> cPtr->cardPrice11 >> cPtr->cardFee11;
		isOpened = true;
	}

	gPtr->AddObjectToCell(cPtr);
}

CardEleven::~CardEleven()
{
}
