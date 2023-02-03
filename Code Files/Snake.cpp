#include "Snake.h"
#include "Ladder.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	type = SNAKE;
}

Snake::Snake() :GameObject(endCellPos)
{
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

void Snake::Save(ofstream& OutFile, ObjectType& type, int& cellNum)
{
	//writing start postion the end position of snake into save file.
	//cellNum is the cell where the object is found(start cell).
	OutFile << cellNum << "     " << CellPosition::GetCellNumFromPosition(endCellPos) << endl;
}

void Snake::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//creating integers to read start and end positions into.
	int startPos;
	int endPos;

	InFile >> startPos >> endPos;

	//creating the snake objects using read parameters and placing it on the grid.

	Snake* sPtr = new Snake(CellPosition::GetCellPositionFromNum(startPos), CellPosition::GetCellPositionFromNum(endPos));

	gPtr->AddObjectToCell(sPtr);
}

bool Snake::IsOverlapping(GameObject* newObj) const
{
	int HPassed, HCurrent;
	Snake* PassedSnake = dynamic_cast<Snake*>(newObj);
	if (PassedSnake)
	{
		HCurrent = (this->GetPosition()).HCell();
		HPassed = (PassedSnake->GetPosition()).HCell();
		if (HCurrent == HPassed)
		{
			int startCurrent = (this->GetPosition()).VCell();
			int endCurrent = (this->GetEndPosition()).VCell();
			int startPassed = (PassedSnake->GetPosition()).VCell();
			int endPassed = (PassedSnake->GetEndPosition()).VCell();
			{
				if ((startPassed >= startCurrent) && (startPassed <= endCurrent))
					return true;
				if ((endPassed >= startCurrent) && (endPassed <= endCurrent))
					return true;
				if ((startCurrent >= startPassed) && (startCurrent <= endPassed))
					return true;
				if ((endCurrent >= startPassed) && (endCurrent <= endPassed))
					return true;
			}
		}
	}
	else {
		Ladder* PassedLadder = dynamic_cast<Ladder*>(newObj);
		HCurrent = (this->GetPosition()).HCell();
		HPassed = (PassedLadder->GetPosition()).HCell();
		if (HCurrent == HPassed)
		{
			int startCurrent = (this->GetPosition()).VCell();
			int endCurrent = (this->GetEndPosition()).VCell();
			int startPassed = (PassedLadder->GetPosition()).VCell();
			int endPassed = (PassedLadder->GetEndPosition()).VCell();
			{
				if (startPassed == endCurrent || startCurrent == endPassed)
					return true;
			}
		}
	}
	return false;
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{

}
