#pragma once
#include "action.h"
#include "Input.h"
#include "Output.h"
#include"grid.h"
#include"CellPosition.h"

class PasteAction : public Action
{
	CellPosition pos;
	int h;
	int v;
public:
	PasteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)
	
	virtual void Execute(); // Creates a new Ladder Object 
	                        // then Sets this Ladder object to the GameObject Pointer of its Cell
	

	virtual ~PasteAction(); // Virtual Destructor
};

