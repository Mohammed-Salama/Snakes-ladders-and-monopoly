#pragma once
#include "Action.h"
class EditCard :
	public Action
{
	CellPosition pos;
	int h;
	int v;

public:

	EditCard(ApplicationManager* pApp);

	virtual void ReadActionParameters(); // Reads Edit action parameters (cellposition )

	virtual void Execute(); // read card parameters if exist


	virtual ~EditCard(); // Virtual Destructor
};

