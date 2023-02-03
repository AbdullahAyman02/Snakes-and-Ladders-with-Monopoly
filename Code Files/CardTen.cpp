#include "CardTen.h"

int CardTen::cardPrice10 = -1;
int CardTen::cardFee10 = -1;
Player* CardTen::owner10 = NULL;
bool CardTen::isSaved = false;
bool CardTen::isOpened = false;

CardTen::CardTen(const CellPosition& pos) : Card9_11(pos)
{
	cardNumber = 10; // setting the inherited cardNumber data member with the card number (10 here)
}

CardTen::CardTen()
{
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardTen...");
	Card9_11::ReadCardParameters(pGrid, cardPrice10, cardFee10);
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid, pPlayer,cardPrice10,cardFee10,owner10);
}

Card* CardTen::Copy()
{
	Card* temp = new CardTen(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardTen::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//If the card parameter was already written, do not write it again
	Card::Save(outFile, type, cellNum);
	if (!isSaved)
	{
		outFile << cardPrice10 << "     " << cardFee10 << endl;
		isSaved = true;
	}
	else
	{
		outFile << endl;
	}
}

void CardTen::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	int cPos;

	InFile >> cPos;

	CardTen* cPtr = new CardTen(CellPosition::GetCellPositionFromNum(cPos));

	if (!isOpened)
	{
		InFile >> cPtr->cardPrice10 >> cPtr->cardFee10;
		isOpened = true;
	}

	gPtr->AddObjectToCell(cPtr);

}

int CardTen::GetCardPrice()
{
	return cardPrice10;
}

void CardTen::Changeowners(Player* newowner)
{
	owner10 = newowner;
}

void CardTen::Resetowner()
{
	owner10 = NULL;
}

CardTen::~CardTen()
{
}
