#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12; // setting the inherited cardNumber data member with the card number (12 here)
}

CardTwelve::CardTwelve()
{
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	if (pPlayer->GetNumofStationsowned() == 0) {
		pGrid->PrintErrorMessage("This player has no stations.");
		return;
	}
	Player* poorestplayer = pGrid->GetPoorestplayer(pPlayer); // getting the poorest player
	if (poorestplayer == pPlayer) // checks if the player landing on the card is the poorest player
		pGrid->PrintErrorMessage("The owner of the most expensive station is already the poorest player.");
	else {
		pPlayer->Transfermostexpensivestation(poorestplayer); // transfers the most expensive station from the calling player to the poorst player
		pGrid->PrintErrorMessage("Most expensive station has been transferred to the poorest player");
	}
}

Card* CardTwelve::Copy()
{
	Card* temp = new CardTwelve(this->GetPosition());
	*temp = *this;
	return temp;
}

void CardTwelve::Save(ofstream& outFile, ObjectType& type, int& cellNum)
{
	//firstly saving cardnumber and position
	//secondly writing the cardParameter if exists
	Card::Save(outFile, type, cellNum);
	outFile << endl;
}

void CardTwelve::Open(ifstream& InFile, ObjectType& type, Grid* gPtr)
{

	//reading card position,creating object and adding object to the grid
	int cPos;

	InFile >> cPos;
	CardTwelve* cPtr = new CardTwelve(CellPosition::GetCellPositionFromNum(cPos));

	gPtr->AddObjectToCell(cPtr);
}

CardTwelve::~CardTwelve()
{
}
