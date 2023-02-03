#include "Card9_11.h"
#include "Player.h"

Card9_11::Card9_11(const CellPosition& pos) : Card(pos)
{

}

Card9_11::Card9_11()
{
}

void Card9_11::ReadCardParameters(Grid* pGrid,int &cp,int &cf)
{
	//Getting a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//Reading an Integer from the user using the Input class and set the cardPrice and cardFee parameters with it
	if (cp == -1 && cf == -1) {
		pOut->PrintMessage("Enter the price of the station...");
		cp = pIn->GetInteger(pOut);

		pOut->PrintMessage("Enter the fee to be paid by other players...");
		cf = pIn->GetInteger(pOut);
	}
	//Clearing the status bar
	pOut->ClearStatusBar();
}


void Card9_11::Apply(Grid* pGrid, Player* pPlayer,int &cp,int &cf,Player*& pl)
{
	//Calling Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	//Getting a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	string wanttobuy;
	int x, y;

	if (!pl) /*checks if the station is not already owned*/ {
		if (pPlayer->GetWallet() < cp) /*checks if player has enough coins to buy the station*/ {
			pGrid->PrintErrorMessage("Unfortunately, you do not have enough coins so you cannot buy this station.");
			return;
		}
		//checks if the player wishes to buy the station or not
		pOut->PrintMessage("This station is not owned. Do you wish to buy it? (y/n)");
		wanttobuy = pIn->GetSrting(pOut);
		if (wanttobuy == "y" || wanttobuy == "Y" || wanttobuy == "yes" || wanttobuy == "YES")/*if the player wants to buy the station*/ {
			pPlayer->DecrementWallet(cp); //decreases wallet of the player by the card price
			pGrid->PrintErrorMessage("Congratualtions! You now own station " + to_string(cardNumber) + " .Click to continue...");
			pPlayer->Setstationsowned(*this); // adds the station to the stations owned by the player 
			pl = pPlayer; // sets the owner of this station as the current pPlayer
		}
		else if (wanttobuy == "n" || wanttobuy == "N" || wanttobuy == "no" || wanttobuy == "NO")/*if the player does not want to buy the station*/ {
			pGrid->PrintErrorMessage("OK then. Your loss anyway.");
		}
	}
	else /*if the station is already owned */ {
		if (pPlayer == pl) //the current pPlayer is the owner of the station
			pGrid->PrintErrorMessage("You already own this station!");
		else /*the current pPlayer does not own this station */ {
			pGrid->PrintErrorMessage("Unfortunately, you landed on a station already owned by player " + to_string(pl->GetPlayernum()) + " . You have to pay this player " + to_string(cf) + " coins.");
			pl->Transfercoins(pPlayer,cf); //transfers coins from the pPlayer to the owner
		}
	}
}

Card9_11::~Card9_11()
{
}
