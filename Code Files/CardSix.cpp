#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

CardSix::CardSix()
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardSix: Select a Destination Cell ...");
	destcell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

Card* CardSix::Copy()
{
	Card* temp = new CardSix(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardSix::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position from file
	int cPos;

	InFile >> cPos;
	//creating the cardobject with read parameters and placing it on the grid
	CardSix* cPtr = new CardSix(CellPosition::GetCellPositionFromNum(cPos));
	int OpenedCellNum;
	InFile >> OpenedCellNum;
	//reading the card parameter from the file.
	cPtr->destcell = CellPosition::GetCellPositionFromNum(OpenedCellNum);




	gPtr->AddObjectToCell(cPtr);
}

void CardSix::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << CellPosition::GetCellNumFromPosition(destcell) << endl;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, destcell);
}

CardSix::~CardSix()
{
}
