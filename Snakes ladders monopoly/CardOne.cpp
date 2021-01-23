#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
	added = true;
}


CardOne::~CardOne(void)
{
}

CardOne::CardOne()
{

}

CardOne::CardOne(CellPosition pos ,int w):Card(pos)
{
	walletAmount=w;
	cardNumber = 1;
	isFirst = true;
}



bool CardOne::getadded() {
	return added;
}

void CardOne::ReadCardParameters(Grid * pGrid)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output *pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	if (isFirst)
	{
		pOut->PrintMessage("New  CardOne: Enter its wallet amount");
	}
	else
	{
		pOut->PrintMessage("edit CardOne: Enter its wallet amount");
	}
	int amount = pIn->GetInteger(pOut);
	if (amount > 0) {
		walletAmount = amount;
	}
	else {
		
		added = false ;
	}
	isFirst = false;
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("this card decrements your wallet with  amount =" + to_string(walletAmount) + "  click to continue");
	Input * pIn = pGrid->GetInput();
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
}



void CardOne::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file
{

	if(Type==CARDONE)
	 {
		 OutFile<<cardNumber<<"\t"<<position.GetCellNum()<<"\t"<<walletAmount<<endl;
		 
	 }
	

}


 void CardOne::Load(ifstream &Infile,GameObject*p,Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	 int cellnum;
	 cardNumber = 1;
	 Infile >> cellnum >> walletAmount;
	 position = CellPosition::GetCellPositionFromNum(cellnum);

	pGrid->AddObjectToCell(p);
	 
}

 
 Card* CardOne::GetCopy(CellPosition pos)
{
	return new CardOne(pos,walletAmount);
}