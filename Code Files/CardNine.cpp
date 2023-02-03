#include "CardNine.h"

int CardNine::cardPrice9 = -1;
int CardNine::cardFee9 = -1;
Player* CardNine::owner9 = NULL;
bool CardNine::isSaved = false;
bool CardNine::isOpened = false;

CardNine::CardNine(const CellPosition& pos) : Card9_11(pos) 
{
	cardNumber = 9; // setting the inherited cardNumber data member with the card number (9 here)
}

CardNine::CardNine()
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("New CardNine...");
	Card9_11::ReadCardParameters(pGrid, cardPrice9, cardFee9);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card9_11::Apply(pGrid,pPlayer,cardPrice9,cardFee9,owner9);
}

Card* CardNine::Copy()
{
	Card* temp = new CardNine(this->GetPosition());
	*temp = *this;
	return temp;
}


void CardNine::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	int cPos;

	InFile >> cPos;

	CardNine* cPtr = new CardNine(CellPosition::GetCellPositionFromNum(cPos));

	if (!isOpened)
	{
		InFile >> cPtr->cardPrice9 >> cPtr->cardFee9;
		isOpened = true;
	}

	gPtr->AddObjectToCell(cPtr);

}

void CardNine::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	Card::Save(outFile, type, cellNum);
	if (!isSaved)
	{
		//secondly writing the cardParameters
		outFile << cardPrice9 << "     " << cardFee9 << endl;
		isSaved = true;
	}
	else
	{
		outFile << endl;
	}
}

int CardNine::GetCardPrice()
{
	return cardPrice9;
}

void CardNine::Changeowners(Player* newowner)
{
	owner9 = newowner;
}

void CardNine::Resetowner()
{
	owner9 = NULL;
}

CardNine::~CardNine()
{
}

