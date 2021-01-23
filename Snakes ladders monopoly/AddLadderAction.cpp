#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters 
	int startcell=CellPosition::GetCellNumFromPosition(startPos);
	int endcell=CellPosition::GetCellNumFromPosition(endPos);
	if(startcell>endcell || (startPos.HCell()!=endPos.HCell()))
		validLadder=false;
	else 
		validLadder=true;

	if (CellPosition::GetCellNumFromPosition(startcell) == 1)
	{
		validLadder1 = false;
	}
	else
	{
		validLadder1 = true;
	}

	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	bool added=true;   
	bool CheckOverLapping=false;
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	ReadActionParameters();
	if(validLadder)
	{

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	

	

	// Add the card object to the GameObject of its Cell:
	
    added = pGrid->AddObjectToCell(pLadder);
    CheckOverLapping=pGrid->IsOverLapping(pLadder);
	if(CheckOverLapping || !(validLadder1))
		{
			pGrid->RemoveObjectFromCell(startPos);
			//added=false;
	    }

	}
	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	if(validLadder==false)
	{
		pGrid->PrintErrorMessage("Error: THE END CELL SHOULD BE GREATER THAN THE START CELL  ! Click to continue ...");
	}
	if(CheckOverLapping)
	{
		pGrid->PrintErrorMessage("Error: OVERLAPPING!!  Click to continue ...");
	}
	if (validLadder1 == false)
	{
		pGrid->PrintErrorMessage("Error: The Start Cell Of The Ladder Can not be 1   Click to continue ...");

	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
