#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"

class Exit : public Action
{

public:
	Exit(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell

	virtual ~Exit(); // Virtual Destructor



};

