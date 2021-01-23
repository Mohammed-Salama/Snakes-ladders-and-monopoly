#pragma once
#include "Action.h"

class SwitchToDesignModeAction : public Action
{
	int mymode;  // 1 for design mode 2 for playmode
public:

	SwitchToDesignModeAction(ApplicationManager *pApp); // A Constructor
	
	virtual ~SwitchToDesignModeAction(); // Virtual Destructor
	void ReadActionParameters();

	virtual void Execute();

};
