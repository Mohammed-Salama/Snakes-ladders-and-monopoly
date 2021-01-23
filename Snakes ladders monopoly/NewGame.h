#pragma once
#include "action.h"
class NewGame :public Action
{
public:
	NewGame(ApplicationManager *pApp);
		
	virtual void ReadActionParameters(); 
	
	virtual void Execute();
	virtual ~NewGame();
};

