#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

CardThree::CardThree()
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->setExtraDiceRoll(); // This sets the flag parameter of player so that if in RollDice the flag is true, the grid does not advance
								 // to the next player
}

Card* CardThree::Copy()
{
	Card* temp = new CardThree(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardThree::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position,creating object and adding object to the grid
	int cPos;

	InFile >> cPos;
	CardThree* cPtr = new CardThree(CellPosition::GetCellPositionFromNum(cPos));




	gPtr->AddObjectToCell(cPtr);


}

void CardThree::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << endl;
}

CardThree::~CardThree()
{
}
