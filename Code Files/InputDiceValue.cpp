#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceValue::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* gPtr = pManager->GetGrid();
	Input* iPtr = gPtr->GetInput();
	Output* oPtr = gPtr->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	if (gPtr->GetEndGame())
	{
		gPtr->PrintErrorMessage("EndGame Reached, Congratulations! Please Exit ...");
		return;
	}

	//// -- If not ended, do the following --:
	if (gPtr->GetCurrentPlayer()->InPrison())
	{
		gPtr->GetCurrentPlayer()->Move(gPtr, -1);
		gPtr->PrintErrorMessage("You are frozen, click to continue");
		gPtr->AdvanceCurrentPlayer();
		return;
	}
	// 3- Get the "current" player from pGrid

	Player* currPlayer = gPtr->GetCurrentPlayer();

	// getting user input:-

	oPtr->PrintMessage("Input Dice Value: ");
	int diceNumber = iPtr->GetInteger(oPtr);
	while (diceNumber > 6 || diceNumber < 1)
	{
		oPtr->PrintMessage("Invalid! please input a valid dice value:");
		diceNumber = iPtr->GetInteger(oPtr);
	}

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
		gPtr->PrintErrorMessage("You have an extra dice roll, click to continue ...");
		currPlayer->setExtraDiceRoll(false);
	}
	else
	{
		gPtr->AdvanceCurrentPlayer();
	}
	oPtr->ClearStatusBar();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceValue::~InputDiceValue()
{
}
