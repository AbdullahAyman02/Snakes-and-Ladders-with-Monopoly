#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,			// Add Ladder Action
	ADD_SNAKE,			// Add Snake Action	
	ADD_CARD,			// Add Card Action	
	COPY_CARD,			// Copy Card Action
	CUT_CARD,			// Cut Card Action
	PASTE_CARD,			// Paste Card Action
	DELETE_GAME_OBJECT, // Delete Game Object Action
	SAVE_GRID,			// Save Grid Action
	OPEN_GRID,			// Open Saved Grid Action
	TO_PLAY_MODE,		// Go to Play Mode
	EXIT,				// Exit Application

	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,		 // Roll Dice Action
	INPUT_DICE_VAUE, // Input Dice Value Action
	NEW_GAME,		 // Start a New Game
	TO_DESIGN_MODE,	 // Go to Design Mode
	EXITP,		 // Exit Application from Play Mode

	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

enum ObjectType
{
	LADDER,
	SNAKE,
	CARD
};

#endif