#include "Ladder.h"
#include "Snake.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	type = LADDER;
}

Ladder::Ladder()
{
}


void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}


void Ladder::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//writing start postion the end position of ladder into save file.
	//cellNum is the cell where the object is found(start cell).
	outFile << cellNum << "     " << CellPosition::GetCellNumFromPosition(endCellPos) << endl;
}

void Ladder::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//creating integers to read start and end positions into.
	int startPos = 0;
	int endPos = 0;



	InFile >> startPos >> endPos;

	//creating the ladder objects using read parameters and placing it on the grid.

	Ladder* pLadder = new Ladder(CellPosition::GetCellPositionFromNum(startPos), CellPosition::GetCellPositionFromNum(endPos));

	gPtr->AddObjectToCell(pLadder);
}

bool Ladder::IsOverlapping(GameObject* newObj) const
{
	Ladder* PassedLadder = dynamic_cast<Ladder*>(newObj);
	if (PassedLadder)
	{
		int HCurrent = (this->GetPosition()).HCell();
		int HPassed = (PassedLadder->GetPosition()).HCell();
		if (HCurrent == HPassed)
		{
			int startCurrent = (this->GetPosition()).VCell();
			int endCurrent = (this->GetEndPosition()).VCell();
			int startPassed = (PassedLadder->GetPosition()).VCell();
			int endPassed = (PassedLadder->GetEndPosition()).VCell();
			{
				if ((startPassed <= startCurrent) && (startPassed >= endCurrent))
					return true;
				if ((endPassed <= startCurrent) && (endPassed >= endCurrent))
					return true;
				if ((startCurrent <= startPassed) && (startCurrent >= endPassed))
					return true;
				if ((endCurrent <= startPassed) && (endCurrent >= endPassed))
					return true;
			}
		}
	}
	else {
		Snake* PassedSnake = dynamic_cast<Snake*>(newObj);
		int HCurrent = (this->GetPosition()).HCell();
		int HPassed = (PassedSnake->GetPosition()).HCell();
		if (HCurrent == HPassed)
		{
			int startCurrent = (this->GetPosition()).VCell();
			int endCurrent = (this->GetEndPosition()).VCell();
			int startPassed = (PassedSnake->GetPosition()).VCell();
			int endPassed = (PassedSnake->GetEndPosition()).VCell();
			{
				if (startPassed == endCurrent || startCurrent == endPassed)
					return true;
			}
		}
	}
	return false;
}

Ladder::~Ladder()
{
	
}
