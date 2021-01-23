#include "CardNine.h"



CardNine::CardNine(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9;        // set the inherited cardNumber data member with the card number (9 here)
}



void  CardNine::ReadCardParameters(Grid * pGrid) {

	

	Output* pOut = pGrid->GetOutput();     //getting pointer to input and outputs interfaces from the grid 
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("please click cell needed to move to  ");  //message to instruct user what to choose cell 
	cpos = pIn->GetCellClicked();
	cellnumber = cpos.GetCellNum();
	pOut->ClearStatusBar();

}
void CardNine::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();
	
	pOut->PrintMessage("this card takes you to cell number " + to_string(cellnumber) + "  click to continue");
	Input * pIn = pGrid->GetInput();
	pIn->GetCellClicked();
	
	pGrid->UpdatePlayerCell(pPlayer, cpos.GetCellPositionFromNum(cellnumber));
	pOut->ClearStatusBar();
}

CardNine::CardNine()
{
}

void CardNine::Save(ofstream &OutFile, ObjectType Type)  // Saves the GameObject parameters to the file
{
	if (Type == CARDNINE)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() <<"\t"<< cellnumber<< endl;

	}


}


void CardNine::Load(ifstream &Infile, GameObject*p, Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	
	int cellnum;
	cardNumber = 9;
	Infile >> cellnum >> cellnumber;
	position = CellPosition::GetCellPositionFromNum(cellnum);

	pGrid->AddObjectToCell(p);

}



CardNine::~CardNine()
{
}


CardNine::CardNine(CellPosition pos , int n):Card(pos)
{
	cellnumber=n;
	cardNumber = 9;   
}

Card* CardNine::GetCopy(CellPosition pos)
{
	return new CardNine(pos,cellnumber);
}