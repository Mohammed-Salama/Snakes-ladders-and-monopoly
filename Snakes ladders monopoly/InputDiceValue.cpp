#include "InputDiceValue.h"
#include "Action.h"
#include "Grid.h"
#include "Player.h"
InputDiceValue::InputDiceValue (ApplicationManager *pApp ) :Action (pApp) 
{
}
void InputDiceValue::ReadActionParameters()
{
	

	// no parameters to read from user
}
void InputDiceValue::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// == Here are some guideline steps (numbered below) to implement this function ==
	pOut->PrintMessage("Please enter a dice value from 1 to 6");
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	bool GameEnded;
	
	GameEnded=pGrid->GetEndGame();
	// -- If not ended, do the following --:
	int diceNumber;
	// 2- Generate a random number from 1 to 6 --> This step is done for you
	if (!GameEnded)
	{
		int dicevalue = pIn->GetInteger(pOut);
		if (dicevalue >0 && dicevalue<7)
		{
			diceNumber=dicevalue ;
		}
		else
		{
			pOut->PrintMessage("Invalid Value");
			return;
		}
	 // time is for different seed each run
	 // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	Player * p;
	p=pGrid->GetCurrentPlayer();
	// 4- Move the currentPlayer using function Move of class player
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
	// 4- Move the currentPlayer using function Move of class player
	if (!check)
	{
		if  (diceNumber>dc)
		{
			diceNumber=dc;
		}
	}
	p->Move(pGrid,diceNumber);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
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
InputDiceValue::~InputDiceValue(void)
{
}
