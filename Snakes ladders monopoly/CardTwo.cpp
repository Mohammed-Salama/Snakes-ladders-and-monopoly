#include "CardTwo.h"



CardTwo::CardTwo(const CellPosition & pos) : Card(pos)
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
	added = true;
	bool isFirst = true;
}



CardTwo::~CardTwo()
{
}

bool CardTwo::getadded() {
	return added;
}
void CardTwo::ReadCardParameters(Grid * pGrid)
{


	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Output *pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();
	if (isFirst)
	{
		pOut->PrintMessage("New  CardTwo: Enter its wallet amount");
	}
	else
	{
		pOut->PrintMessage("edit CardTwo: Enter its wallet amount");
	}
	int amount = pIn->GetInteger(pOut);
	if (amount > 0) {
		walletAmount = amount;
		
	}
	else {
		added = false;
	}

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	isFirst = false;
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("this card increments your wallet with  amount =" + to_string(walletAmount) + "  click to continue");
	Input * pIn = pGrid->GetInput();
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}

CardTwo::CardTwo()
{
}

void CardTwo::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file

 {
	 if(Type==CARDTWO)
	 {
		 OutFile<<cardNumber<<"\t"<<position.GetCellNum()<<"\t"<<walletAmount<<endl;
		 
	 }
	 

}


 void CardTwo::Load(ifstream &Infile,GameObject*p,Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	 int cellnum;
	 cardNumber = 2;
	 Infile >> cellnum >> walletAmount;
	 position = CellPosition::GetCellPositionFromNum(cellnum);
	pGrid->AddObjectToCell(p);
}

 CardTwo::CardTwo(CellPosition pos ,int w):Card(pos)
{
	walletAmount = w;
	cardNumber=2; 
}

 Card* CardTwo::GetCopy(CellPosition pos)
 {
	 return (new CardTwo(pos,walletAmount));
 }

