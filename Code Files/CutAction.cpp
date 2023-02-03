#include "CutAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"


CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{
	ClipboardCard = NULL;
}

void CutAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click on the source cell...");
	cardPosition = pIn->GetCellClicked();
	if (cardPosition.IsValidCell())
	{
		ClipboardCard = pGrid->GetCard(cardPosition);
	}
	pOut->ClearStatusBar();
}

void CutAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (ClipboardCard)
	{
		pGrid->SetClipboard(ClipboardCard);
		pGrid->PrintErrorMessage("Card Cut Successfully! Click to continue...");
		pGrid->RemoveObjectFromCell(cardPosition);
		return;
	}
	pGrid->PrintErrorMessage("Card Not Cut. Click to continue...");
}

CutAction::~CutAction()
{
}