#include "CardEight.h"



CardEight::CardEight()
{
}

CardEight::CardEight(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8;
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)  //this card prevents player form rolling the next turn 
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("this card prevents you from rolling  the dice  the next turn");
	pPlayer->setFreezed(true);
	pOut->ClearStatusBar();
}


void CardEight::Save(ofstream &OutFile, ObjectType Type)  // Saves the GameObject parameters to the file
{
	if (Type == CARDEIGHT)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;

	}


}


void CardEight::Load(ifstream &Infile, GameObject*p, Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	int cellnum;
	cardNumber = 8;
	Infile >> cellnum;
	position = CellPosition::GetCellPositionFromNum(cellnum);
	pGrid->AddObjectToCell(p);

}


CardEight::~CardEight()
{
}


Card* CardEight::GetCopy(CellPosition pos)
{
	return new CardEight(pos);
}