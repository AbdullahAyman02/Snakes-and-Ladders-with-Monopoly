#include "OpenGridAction.h"
#include <string>
#include "Grid.h"
#include <fstream>
#include "Ladder.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp)
{

}

void OpenGridAction::ReadActionParameters()
{
	Grid* gPtr = pManager->GetGrid();
	Input* iPtr = gPtr->GetInput();
	Output* oPtr = gPtr->GetOutput();

	//Obtaing file name to load from from the user.
	oPtr->PrintMessage("Enter load file name: ");
	FileName = iPtr->GetSrting(oPtr);
}

void OpenGridAction::Execute()
{
	ReadActionParameters();

	Grid* gPtr = pManager->GetGrid();
	Output* oPtr = gPtr->GetOutput();


	ifstream InFile;
	InFile.open(FileName);

	//Checking if a file exists with this name, if not the action is cancelled.
	if (!InFile.is_open())
	{
		gPtr->PrintErrorMessage("File does not exist! Click to continue");
		return;
	}

	//Firstly clearng the grid to add objects from the saved file.
	gPtr->ClearGrid();

	//calling open on each object type through grid
	gPtr->OpenAll(InFile, LADDER);
	gPtr->UpdateInterface();
	gPtr->OpenAll(InFile, SNAKE);
	gPtr->UpdateInterface();
	gPtr->OpenAll(InFile, CARD);
	gPtr->UpdateInterface();

	InFile.close();

	gPtr->PrintErrorMessage("File loaded successfully!!");

}
