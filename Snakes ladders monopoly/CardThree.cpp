#include "CardThree.h"
#include"Ladder.h"

CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3;
}

void  CardThree::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();       //get pointer to input and outputs 
	Input * pIn = pGrid->GetInput();
	pOut->PrintMessage("this card takes you to the nearest ladder if found .. click to continue ");
	pIn->GetCellClicked();
	CellPosition c = pPlayer->GetCell()->GetCellPosition();   // taking the position of current cell
	Ladder* L = pGrid->GetNextLadder(c);
	if (L)
	{
		pGrid->UpdatePlayerCell(pPlayer, L->GetStartPosition());//the player now is in the start the nearest ladder

	}
	pOut->ClearStatusBar();
}


CardThree::CardThree()
{
}



void CardThree::Save(ofstream &OutFile, ObjectType Type)  // Saves the GameObject parameters to the file
{

	if (Type == CARDTHREE)
	{
		OutFile << cardNumber <<"\t"<< position.GetCellNum() <<  endl;

	}

}


void CardThree::Load(ifstream &Infile, GameObject*p, Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	int cellnum;
	cardNumber = 3;
	Infile >> cellnum;
	position = CellPosition::GetCellPositionFromNum(cellnum);
	pGrid->AddObjectToCell(p);

}


CardThree::~CardThree()
{
}


Card* CardThree::GetCopy(CellPosition pos)
{
	return new CardThree(pos);
}