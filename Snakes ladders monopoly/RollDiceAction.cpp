#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	

	// no parameters to read from user
}

void RollDiceAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->ClearStatusBar();
	bool GameEnded;
	GameEnded=pGrid->GetEndGame();
	// Checking if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (!GameEnded)
	{
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	// Getting the "current" player from pGrid
	Player * p;
	p=pGrid->GetCurrentPlayer();
	//Validatiion to draw the player at cell 99 when he win and print a massege for this
	Cell *cr;
	cr=p->GetCell();
	CellPosition cp;
	cp=cr->GetCellPosition();
	int celln;
	celln=cp.GetCellNum();
	int dc;
	dc=99-celln;
	bool check;
	if (dc>=6)
	{
      check=true;
	}
	else
	{
		check = false;
	}
	if (!check)
	{
		if  (diceNumber>dc)
		{
			diceNumber=dc;
		}
	}
	//Moving the player or recharging his wallet
	p->Move(pGrid,diceNumber);
	// Advancing the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	}
	//Print a massege when a player win
	else 
	{
		string num;
		int pnum;
		Player * p;
	    p=pGrid->GetCurrentPlayer();
		pnum = p->GetPlayerNum();
		num=to_string(pnum);
		string s ;
		s="Player Num "+num +" Win";
		pOut->PrintMessage(s);
		return;
	}


	
}

RollDiceAction::~RollDiceAction()
{
}
