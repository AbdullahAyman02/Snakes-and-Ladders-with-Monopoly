#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{

}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	ReadActionParameters();
	
	Grid* pGrid = pManager->GetGrid();

	Snake* pSnake = new Snake(startPos, endPos);

	if (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, Click to continue...");
		return;
	}

	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Snake must be on the same column, Click to Continue...");
		return;
	}

	if (startPos.VCell() == 8)
	{
		pGrid->PrintErrorMessage("Snake cannot be on the last row, Click to Continue...");
		return;
	}

	if (CellPosition::GetCellNumFromPosition(endPos) >= CellPosition::GetCellNumFromPosition(startPos))
	{
		pGrid->PrintErrorMessage("Start can't be below end");
		return;
	}

	if (startPos.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("Snake cannot be on cellNum99, Click to Continue...");
		return;
	}

	if (!pGrid->IsOverlapping(pSnake))
	{
		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}
	else
		pGrid->PrintErrorMessage("Snake Overlapping with another snake or ladder.Click to continue...");
}

AddSnakeAction::~AddSnakeAction()
{
}
