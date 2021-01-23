#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include<fstream>


class SaveGridAction : public Action
{
	Grid* pGrid; 
	Output* pOut ;
	Input* pIn ;
	string filename;

    //int ladderNum;
	//int snakeNum;
	//int cardNum;

	

public:

	ofstream OutFile;
	

	SaveGridAction(ApplicationManager *pApp); // A Constructor
	virtual void ReadActionParameters();
	virtual void Execute(); 

	//int CalcLadderNum();
	//int CalcSnakeNum();
	//int CalcCardNum();


	virtual ~SaveGridAction(); // Virtual Destructor
};

