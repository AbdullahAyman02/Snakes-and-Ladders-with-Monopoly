#pragma once
#include "Action.h"
class PasteAction :  public Action
{
	// [Action Parameters]
	CellPosition cardDestination; // 1- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:
	PasteAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~PasteAction(); // A Virtual Destructor
};