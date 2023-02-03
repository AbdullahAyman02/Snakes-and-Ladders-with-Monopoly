#include "SaveGridAction.h"
#include <string>
#include "Grid.h"
#include <fstream>

using namespace std;

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* gPtr = pManager->GetGrid();
	Input* iPtr = gPtr->GetInput();
	Output* oPtr = gPtr->GetOutput();

	//Getting filename from the user
	oPtr->PrintMessage("Enter save file name: ");
	fileName = iPtr->GetSrting(oPtr);






}

void SaveGridAction::Execute()
{

	ReadActionParameters();

	//creating output file
	ofstream outFile;
	outFile.open(fileName);




	Grid* gPtr = pManager->GetGrid();

	//saving all gameobjects through grid.
	gPtr->SaveAll(outFile, LADDER);
	gPtr->SaveAll(outFile, SNAKE);
	gPtr->SaveAll(outFile, CARD);


	outFile.close();

	gPtr->PrintErrorMessage("Grid saved successfully! Click to continue");


}
