#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include <fstream>
#include "Snake.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false
		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
bool Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (!pPrevObject)
			return false;
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
		return true;
	}
	return false;
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	
	player->SetStepCount(newCell->GetCellPosition().GetCellNum());
	// Draw the player's circle on the new cell position
	player->Draw(pOut);
	UpdateInterface();	//To draw the player before applying the effect of a gameobject in case of one
	GameObject* gameobject = newCell->GetGameObject(); //In case gamebjects lead to each other, to prevent redundancy
	if (gameobject)									   //in cases of a continuous loop of gameobjects
	{
		gameobject->Apply(this, player);
		player->Draw(pOut);
		UpdateInterface();
	}
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard->Copy();
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			Ladder* temp = CellList[i][j]->HasLadder();
			if (temp)
				return temp;

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Player* Grid::GetNextPlayer(Player* p)
{
	return p->Findnextplayer(PlayerList, MaxPlayerCount); // Gets the next player, if any
}

Card* Grid::GetCard(const CellPosition& position)
{
	int i = position.HCell();
	int j = position.VCell();
	
	Card* temp = CellList[j][i]->HasCard(); // checks if the passed position contains a card
	return temp;
}

bool Grid::isEmpty(const CellPosition& position) const
{
	int i = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	int j = position.VCell(); // represents the start vCell in the current row to search for the ladder in
	///TODO: Check if CellList[i][j] has a ladder, if yes return it
	GameObject* temp = CellList[j][i]->GetGameObject();
	if (temp)
		return false;
	return true;
}

Player* Grid::GetPoorestplayer(Player* p)
{
	return p->Findpoorestplayer(PlayerList, MaxPlayerCount);
}

void Grid::ResetAllPlayers()
{
	CellPosition tempcell(8, 0);

	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i]->ResetPlayer();
		UpdatePlayerCell(PlayerList[i], tempcell);
	}
	currPlayerNumber = 0;
}

void Grid::SaveAll(ofstream& outFile, ObjectType type)
{

	//looping on all cells to count the number of gameobjects of specified type
	GameObject* currObject = NULL;
	int NumberOfObjects = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			currObject = CellList[i][j]->GetGameObject();
			if (currObject)
			{


				if (currObject->getObjectType() == type)
				{
					NumberOfObjects++;
				}
			}

		}

	}

	//writing number of gameobjects of specified type in save file
	outFile << NumberOfObjects << endl;


	currObject = NULL;
	int cellNum = 0;

	//looping on all cells, if the cell includes specified game object, call the object's save function.
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			currObject = CellList[i][j]->GetGameObject();
			cellNum = CellPosition::GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
			if (currObject)
			{
				if (currObject->getObjectType() == type)
				{
					currObject->Save(outFile, type, cellNum);
				}
			}

		}
	}
}


//Clearing the grid by removing all objects from the cells
void Grid::ClearGrid() //
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
		}
	}
}

void Grid::OpenAll(ifstream& InFile, ObjectType type)
{
	//obtaining number of gameobjects of specific type from the file
	int NumberOfObjects = 0;
	InFile >> NumberOfObjects;
	//creating a dummy gameobject to be able call its open function
	GameObject* currObject;
	switch (type)
	{
	case LADDER:  currObject = new Ladder(); break;
	case SNAKE:  currObject = new Snake(); break;
	case CARD: currObject = new Card(); break;
	}
	//if there are n objects in savefile, open n times
	for (int i = 0; i < NumberOfObjects; i++)
	{
		currObject->Open(InFile, type, this);
	}

}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}

	if (Clipboard)
		delete Clipboard; //If Clipboard not empty
}

bool Grid::IsOverlapping(GameObject* newObj) const
{
	for (int i = NumVerticalCells-1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* temp = CellList[i][j]->GetGameObject();
			if (temp)
			{
				bool check = temp->IsOverlapping(newObj);
				if (check)
					return true;
			}
		}
	}
	return false;
}