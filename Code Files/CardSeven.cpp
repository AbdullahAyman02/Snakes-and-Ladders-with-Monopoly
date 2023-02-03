#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7)
}

CardSeven::CardSeven()
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Player* nextplayer = pGrid->GetNextPlayer(pPlayer); // gets a pointer to the next player
	if (nextplayer) {
		const CellPosition startcell(1); // a temporary CellPosition of cellnumber 1
		pGrid->UpdatePlayerCell(nextplayer, startcell); // returns the player to cell 1
	}
	else
		pGrid->PrintErrorMessage("There are no players after the current player."); //if there are no players after the current player
}

Card* CardSeven::Copy()
{
	Card* temp = new CardSeven(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardSeven::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{
	//reading card position,creating object and adding object to the grid
	int cPos;

	InFile >> cPos;
	CardSeven* cPtr = new CardSeven(CellPosition::GetCellPositionFromNum(cPos));




	gPtr->AddObjectToCell(cPtr);
}

void CardSeven::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << endl;
}

CardSeven::~CardSeven(void)
{
}
