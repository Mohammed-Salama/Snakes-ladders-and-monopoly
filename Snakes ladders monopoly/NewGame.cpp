#include "NewGame.h"
#include "Grid.h"
#include "Player.h"
#include "Cell.h"
NewGame::NewGame(ApplicationManager *pApp) : Action (pApp)
{
}
void NewGame::ReadActionParameters()
{
	// no parameters to read from user
}
void NewGame::Execute() 
{
	Grid * pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Player * p;
	CellPosition pos;
	p=pGrid->GetCurrentPlayer();
	Cell *pCell=p->GetCell();
	pGrid->SetCurrPlayerNumber(0);
	for (int i=0 ; i<4 ; i++)
	{
		//Returning all Player opjects to the default values
		p=pGrid->GetCurrentPlayer();
		p->SetWallet(100);
		pos.SetVCell(8);
		pos.SetHCell(0);
		pGrid->UpdatePlayerCell(p , pos);
		p->SetTurnCount(0);
		p->SetAttackNumber(0);
        p->SetcBurn(0);
	    p->Setcpoison(0);
	    p->SetUsedice(0);
		p->SetnBurn(0);
		p->SetnPoison(0);
	    p->SetUsedPoison(0);
	    p->SetUsedLight(0);
	    p->SetUsedFire(0);
		p->setFreezed(false);
		p->setDebited(false);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrPlayerNumber(0);
	pGrid->SetEndGame(false);
	pOut->ClearStatusBar();

}
NewGame::~NewGame()
{
}
