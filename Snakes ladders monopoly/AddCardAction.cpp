#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardThree.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardTherteen.h"
#include "CardFourteen.h"
AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}


void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Grid* pGrid = pManager->GetGrid();
	// 1- Get a Pointer to the Input / Output Interfaces
	Output* pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Add card ,please insert card number... ");

	cardNumber = pIn->GetInteger(pOut);
	if (cardNumber < 1 || cardNumber>14) {
		pOut->PrintMessage("invalid card number ");
		return;
	}
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("please  select the cell needed to add card on it ");
	cardPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters
	if (CellPosition::GetCellNumFromPosition(cardPosition) == 1 || CellPosition::GetCellNumFromPosition(cardPosition) == 99)
	{
		validCard = false;
	}
	else 
	{
		validCard = true;
	}

	//ana msh fahma lih point 4 tt3emel ana el validation automatically done in setters
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	if (validCard == false)
	{
		pManager->GetGrid()->PrintErrorMessage("Error it can not be added");
		return;

	}
	
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 2:
		pCard = new CardTwo(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 3:
		pCard = new CardThree(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 4:
		pCard = new CardFour(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 5:
		pCard = new CardFive(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 6:
		pCard = new CardSix(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 7:
		pCard = new CardSeven(cardPosition); ////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 8:
		pCard = new CardEight(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 9:
		pCard = new CardNine(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 10:
		pCard = new CardTen(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 11:
		pCard = new CardEleven(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 13:
		pCard = new CardTherteen(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;
	case 14:
		pCard = new CardFourteen(cardPosition);////////////////////////////////////////////////// PASTE ACTION /////////////////////////////////////////
		break;

		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{

		int checkForDrow = true;
		// A- We get a pointer to the Grid from the ApplicationManager
		Output * pOut = pManager->GetGrid()->GetOutput();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pManager->GetGrid());

		if (pCard->getadded()) {
			// C- Add the card object to the GameObject of its Cell:
			checkForDrow = pManager->GetGrid()->AddObjectToCell(pCard);
		}
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		else
		{
			pManager->GetGrid()->PrintErrorMessage("Error it can not be added");
		}

	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
