#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"         
#include "AddSnakeAction.h"
#include "SwitchToPlayModeAction.h"
#include "SwitchToDesignModeAction.h"
#include"SaveGridAction.h"
#include"LoadGridAction.h"
#include"CopyAction.h"
#include"PasteAction.h"
#include"CutAction.h"
#include"DeleteGameOpject.h"
#include"NewGame.h"
#include"inputDiceValue.h"
#include"Exit.h"
#include "EditCard.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case EXIT:
		//pAct= new Exit(this);
		break;

	case TO_PLAY_MODE:
		//pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		pAct= new SwitchToPlayModeAction(this);
		break;

	case EDIT_CARD:
		pAct = new EditCard(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		//pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		pAct= new SwitchToDesignModeAction(this);
		break;

	case SAVE:
	    pAct= new SaveGridAction(this);
	    break;

	case OPEN:
		pAct= new LoadGridAction(this);
		break;

	case COPY:
		pAct= new CopyAction(this);
		break;

	case PASTE:
		pAct= new PasteAction(this);
		break;

	case CUT:
		pAct= new CutAction(this);
		break;

	case DELETe:
		pAct= new DeleteGameOpject(this);
		break;

	case NEW_GAME:
		pAct= new NewGame(this);
		break;
		

	case INPUT_VALUE:
		pAct= new InputDiceValue(this);
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
