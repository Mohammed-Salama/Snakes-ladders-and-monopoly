#include "CopyAction.h"


CopyAction::CopyAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyAction::~CopyAction()
{
}

void CopyAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Copy Action :Click on the card to copy");
	pos=pIn->GetCellClicked();
	h=pos.HCell();
	v=pos.VCell();

	pOut->PrintMessage("Click to continue");
	pIn->GetUserAction();
	pOut->ClearStatusBar();

	
}

// Execute the action
void CopyAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Card*card=pGrid->hasCard(v,h);
	if(card)
	{
		pGrid->SetClipboard(card);
		
	}
	else
		pOut->PrintMessage("Error:the cell has no card");
}
	
