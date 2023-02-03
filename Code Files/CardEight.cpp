#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8)
}

CardEight::CardEight()
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	// Getting a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// Reading an Integer from the user using the Input class and set the PrisonFee parameter with it
	pOut->PrintMessage("New CardEight: Enter the amount of coins to get out of prison ...");
	PrisonFee = pIn->GetInteger(pOut);

	//Clearing the status bar
	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	// Getting a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	string wanttopay;
	int x, y;

	pOut->PrintMessage("Unfortunately you fell on card 8 which is a prison! Pay the required fee of " + to_string(PrisonFee) + " or stay in prison for 3 turns.");
	if (pPlayer->GetWallet() < PrisonFee) /*checks if the player has enough coins to get out of prison*/ {
		pIn->GetPointClicked(x, y);
		pOut->PrintMessage("You do not have coins to pay the fee so you will stay in prison for 3 turns.");
		pIn->GetPointClicked(x, y);
		pPlayer->SetPrisonCount(); // sets the prison count of the player with 3
		return;
	}
	pIn->GetPointClicked(x, y);
	//if player has enough coins, checks if the player wants to pay the fee and get out of prison or not
	pOut->PrintMessage("Do you want to pay the fee" + to_string(PrisonFee) + " ? (y/n)");
	wanttopay = pIn->GetSrting(pOut);
	if (wanttopay == "y" || wanttopay == "Y" || wanttopay == "yes" || wanttopay == "YES") /*if player chooses to pay the fee*/ {
		pPlayer->DecrementWallet(PrisonFee); // decrements wallet with the prison fee
		pOut->PrintMessage("You are out of prison! Try to stay out of trouble.");
		pIn->GetPointClicked(x, y);
	}
	else if (wanttopay == "n" || wanttopay == "N" || wanttopay == "no" || wanttopay == "NO") /*if player chooses to stay in prison*/ {
		pOut->PrintMessage("You are going to stay in prison for 3 turns.");
		pPlayer->SetPrisonCount(); // sets the prison count of the player with 3
	}
	pOut->ClearStatusBar();
}

Card* CardEight::Copy()
{
	Card* temp = new CardEight(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardEight::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << PrisonFee << endl;

}

void CardEight::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position from file
	int cPos;

	InFile >> cPos;

	//creating the cardobject with read parameters and placing it on the grid
	CardEight* cPtr = new CardEight(CellPosition::GetCellPositionFromNum(cPos));

	//reading the card parameter from the file.
	InFile >> cPtr->PrisonFee;




	gPtr->AddObjectToCell(cPtr);
}