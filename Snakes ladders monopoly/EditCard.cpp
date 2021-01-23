#include "EditCard.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
EditCard::EditCard(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCard::~EditCard()
{
}

void EditCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Edit Action :“click on the source to edit”");
	pos = pIn->GetCellClicked();
	h = pos.HCell();
	v = pos.VCell();

	pOut->PrintMessage("Click to continue");
	pIn->GetUserAction();
	pOut->ClearStatusBar();


}

// Execute the action
void EditCard::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Card* card = pGrid->hasCard(v, h);
	if (card)
	{
		card->SetBool();
		card->ReadCardParameters(pGrid);
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("Error:the cell has no card");
}