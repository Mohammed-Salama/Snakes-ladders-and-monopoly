#include "PasteAction.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardSeven.h"
#include"CardThree.h"

PasteAction::PasteAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteAction::~PasteAction()
{
}

void PasteAction::ReadActionParameters() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Paste Action :Click on the cell to paste");
	pos=pIn->GetCellClicked();
	h=pos.HCell();
	v=pos.VCell();

	//pOut->PrintMessage("Click to continue");
	//pIn->GetUserAction();
	pOut->ClearStatusBar();

	
}

// Execute the action
void PasteAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	GameObject*p;
	Card*card=pGrid->hasCard(v,h);
	if(!card)
	{

		card = pGrid->GetClipboard();
		if (card == NULL)
		{
			pGrid->PrintErrorMessage("The Clipboard is Empty");
			return;
		}

		p=pGrid->GetClipboard()->GetCopy(pos);
		
		

		pGrid->AddObjectToCell(p);
		
	}

	else
		pOut->PrintMessage("Error:the cell has card remember remember");


		
		
	
	
}
	
