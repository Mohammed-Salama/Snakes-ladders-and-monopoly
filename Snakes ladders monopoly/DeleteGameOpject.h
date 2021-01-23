#pragma once
#include "Action.h"
class DeleteGameOpject :public Action
{
	 CellPosition OpjCell;
public:
	DeleteGameOpject(ApplicationManager *pApp);
	virtual void ReadActionParameters(); 
	virtual void Execute();
	virtual ~DeleteGameOpject();
};

