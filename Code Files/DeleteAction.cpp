#include "DeleteAction.h"
#include "Grid.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{

}

void DeleteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Click on a cell to delete its content....");
	cell = pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void DeleteAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	bool removed = pGrid->RemoveObjectFromCell(cell);

	if (!removed)
	{
		pGrid->PrintErrorMessage("This cell is already empty!! ");
	}

	



}

DeleteAction::~DeleteAction()
{

}
