#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

CardFive::CardFive()
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int justRolledDiceNum = pPlayer->GetjustRolledDiceNum();
	int NewCell = pPlayer->GetStepCount() - justRolledDiceNum;
	pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(NewCell));
}

Card* CardFive::Copy()
{
	Card* temp = new CardFive(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardFive::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position,creating object and adding object to the grid
	int cPos;

	InFile >> cPos;
	CardFive* cPtr = new CardFive(CellPosition::GetCellPositionFromNum(cPos));




	gPtr->AddObjectToCell(cPtr);
}

void CardFive::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << endl;
}

CardFive::~CardFive()
{
}
