#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* gPtr = pManager->GetGrid();
	Output* oPtr = gPtr->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	if (gPtr->GetEndGame())
	{
		gPtr->PrintErrorMessage(" Game Over, Congratulations! Please Exit ...");
		return;
	}
	// -- If not ended, do the following --:

	if (gPtr->GetCurrentPlayer()->InPrison())
	{
		gPtr->GetCurrentPlayer()->Move(gPtr, -1); //Prevents player from moving in case the player is frozen (card 4 or 8)
		gPtr->PrintErrorMessage("You are frozen, click to continue");
		gPtr->AdvanceCurrentPlayer();
		return;
	}
	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	
	// 3- Get the "current" player from pGrid

	Player* currPlayer = gPtr->GetCurrentPlayer();

	// 4- Move the currentPlayer using function Move of class player
	currPlayer->Move(gPtr, diceNumber);
	if (gPtr->GetEndGame())
	{
		gPtr->PrintErrorMessage("Congratulations Player " + to_string(gPtr->GetCurrentPlayer()->GetPlayernum()) + "! Please Exit ...");
		return;
	}
	
	// 5- Advance the current player number of pGrid
	if (currPlayer->getExtraDiceRoll())
	{
		gPtr->PrintErrorMessage("You have an extra dice roll, click to continue ..."); //Explained in card 3
		currPlayer->setExtraDiceRoll(false);
	}
	else
	{
		gPtr->AdvanceCurrentPlayer();
	}
	oPtr->ClearStatusBar();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
