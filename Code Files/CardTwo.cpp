#include "CardTwo.h"

#include "Ladder.h"


CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

CardTwo::CardTwo()
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder* ladder = pGrid->GetNextLadder(position);
	if (ladder)
	{
		ladder->Apply(pGrid, pPlayer);
		return;
	}
	pGrid->PrintErrorMessage("No Ladders Ahead, Click to continue...");
}

Card* CardTwo::Copy()
{
	Card* temp = new CardTwo(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardTwo::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position,creating object and adding object to the grid
	int cPos;

	InFile >> cPos;
	CardTwo* cPtr = new CardTwo(CellPosition::GetCellPositionFromNum(cPos));

	


	gPtr->AddObjectToCell(cPtr);


}

void CardTwo::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << endl;
}

CardTwo::~CardTwo()
{
}
