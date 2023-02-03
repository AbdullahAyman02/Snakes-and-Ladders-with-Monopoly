#pragma once
#include "Action.h"

class CopyAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition;  // Cell clicked by user
	Card* ClipboardCard;		// Card copied into clipboard
	// Note: These parameters should be read in ReadActionParameters()

public:
	CopyAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~CopyAction(); // A Virtual Destructor

};