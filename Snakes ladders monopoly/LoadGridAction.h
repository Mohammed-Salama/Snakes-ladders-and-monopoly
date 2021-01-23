#pragma once
#include "action.h"
#include"input.h"
#include"output.h"
#include"grid.h"
#include"AddLadderAction.h"
#include"AddSnakeAction.h"
#include"AddCardAction.h"
#include"ladder.h"
#include"snake.h"
#include"card.h"
#include"Cellposition.h"
#include"cardtwo.h"
#include<fstream>

class LoadGridAction : public Action
{
	Grid* pGrid; 
	Output* pOut ;
	Input* pIn ;
	string filename;

	int ladderNum;
	int snakeNum;
	int numberofcards;
	int cardtype;

public:

	// ifstream Infile;


     LoadGridAction(ApplicationManager *pApp);
	 virtual void ReadActionParameters();
	 virtual void Execute();


	 virtual ~LoadGridAction(); // Virtual Destructor
};

