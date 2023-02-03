#include "PasteAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{
	CellPosition cardPosition; 
	Card* ClipboardCard;		
}

void PasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the destination cell...");
	cardDestination = pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	if (!cardDestination.IsValidCell())
	{
		pGrid->PrintErrorMessage("Destination cell is not a valid cell! Click to continue...");
		return;
	}

	Card* pObj = (pGrid->GetClipboard())->Copy();


	if (pObj && pGrid->isEmpty(cardDestination))
	{
		pObj->SetCardPosition(cardDestination);
		pGrid->AddObjectToCell(pObj);
		pGrid->PrintErrorMessage("Card pasted successfully! Click to continue...");
		return;
	}
	pGrid->PrintErrorMessage("Card not pasted! Please make sure the cell is empty. Click to continue...");
}

PasteAction::~PasteAction()
{
}