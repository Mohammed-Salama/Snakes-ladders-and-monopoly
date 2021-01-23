#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include"cellposition.h"

#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	int startcell=CellPosition::GetCellNumFromPosition(startPos);
	int endcell=CellPosition::GetCellNumFromPosition(endPos);
	if(startcell<endcell || (startPos.HCell() != endPos.HCell()))
		validSnake=false;
	else 
		validSnake=true;

	if (CellPosition::GetCellNumFromPosition(startcell) == 99)
	{
		validSnake1 = false;
	}
	else
	{
		validSnake1 = true;
	}



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute() 
{
	bool checkoverlapp=false;
	bool added=true;
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Create a Snake object with the parameters read from the use
	if(validSnake)
	{
		Snake * pSnake = new Snake (startPos , endPos);

		

		// Add the card object to the GameObject of its Cell:
		
		added = pGrid->AddObjectToCell(pSnake);
		checkoverlapp=pGrid->IsOverLapping(pSnake);
		if(checkoverlapp||!(validSnake1))
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
	if(validSnake==false)
	{
		pGrid->PrintErrorMessage("Error: THE START CELL SHOULD BE GREATER THAN THE END CELL  ! Click to continue ...");
	}
	if(checkoverlapp)
	{
		pGrid->PrintErrorMessage("Error: OVERLAPPING!!  Click to continue ...");
	}
	if (validSnake1 == false)
	{
		pGrid->PrintErrorMessage("Error: The Start Cell Of The Snake Can not be 99   Click to continue ...");
		
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
}