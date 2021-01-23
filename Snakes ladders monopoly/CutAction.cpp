#include "CutAction.h"



CutAction::CutAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutAction::~CutAction()
{
}

void CutAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Cut Action :Click on the card to cut");
	pos=pIn->GetCellClicked();
	h=pos.HCell();
	v=pos.VCell();

	pOut->PrintMessage("Click to continue");
	pIn->GetUserAction();
	pOut->ClearStatusBar();

	
}

// Execute the action
void CutAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Card*card=pGrid->hasCard(v,h);
	if(card)
	{
		pGrid->SetClipboard(card);
		pGrid->RemoveObjectFromCell(pos);    //idk
		
	}
	else
		pOut->PrintMessage("Error:the cell has no card");
}