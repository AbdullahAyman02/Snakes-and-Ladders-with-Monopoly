#include "NewGameAction.h"
#include "Grid.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->SetEndGame(false);
	pGrid->ResetAllPlayers();
	pGrid->PrintErrorMessage("This is a new game! Click to Continue...");
}

NewGameAction::~NewGameAction()
{
}