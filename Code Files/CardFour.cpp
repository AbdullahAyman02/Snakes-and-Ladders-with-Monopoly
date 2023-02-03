#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

CardFour::CardFour()
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetPrisonCount(1); // This freezes the player for one turn
}

Card* CardFour::Copy()
{
	Card* temp = new CardFour(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardFour::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position,creating object and adding object to the grid
	int cPos;

	InFile >> cPos;
	CardFour* cPtr = new CardFour(CellPosition::GetCellPositionFromNum(cPos));




	gPtr->AddObjectToCell(cPtr);
}

void CardFour::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << endl;
}

CardFour::~CardFour()
{
}
