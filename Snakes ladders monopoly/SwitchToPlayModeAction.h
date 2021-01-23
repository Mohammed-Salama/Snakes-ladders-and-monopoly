#pragma once
#include "Action.h"

class SwitchToPlayModeAction : public Action
{
	int mymode;  // 1 for design mode 2 for playmode
public:

	SwitchToPlayModeAction(ApplicationManager *pApp); // A Constructor
	
	virtual ~SwitchToPlayModeAction(); // Virtual Destructor
	void ReadActionParameters();

	virtual void Execute();

};

