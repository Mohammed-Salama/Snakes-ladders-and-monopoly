#include "CardFour.h"
#include "Snake.h"


CardFour::CardFour()
{
}


CardFour::~CardFour()
{
}




CardFour::CardFour(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4;
}

void  CardFour::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();       //get pointer to input and outputs 
	Input * pIn = pGrid->GetInput();
	pOut->PrintMessage("this card takes you to the nearest snake  if found .. click to continue ");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	CellPosition c = pPlayer->GetCell()->GetCellPosition();   // taking the position of current cell
	Snake * s = pGrid->GetNextSnake(c);
	if (s)
	{
		pGrid->UpdatePlayerCell(pPlayer, s->GetStartPosition());


	}
	pOut->ClearStatusBar();
}

void CardFour::Save(ofstream &OutFile, ObjectType Type)  // Saves the GameObject parameters to the file
{

	if (Type == CARDFOUR)
	{
		OutFile << cardNumber <<"\t"<< position.GetCellNum() << endl;

	}


}


void CardFour::Load(ifstream &Infile, GameObject*p, Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	int cellnum;
	cardNumber = 4;
	Infile >> cellnum;
	position = CellPosition::GetCellPositionFromNum(cellnum);
	pGrid->AddObjectToCell(p);

}





Card* CardFour::GetCopy(CellPosition pos)
{
	return new CardFour(pos);
}