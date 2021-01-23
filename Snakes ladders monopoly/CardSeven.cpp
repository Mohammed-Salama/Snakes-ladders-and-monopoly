#include "CardSeven.h"



CardSeven::CardSeven()
{
}

CardSeven::CardSeven(const CellPosition & pos) : Card(pos)
{
	cardNumber = 7;
}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer) 
{
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();
	pOut->PrintMessage("this card gives the current player another roll dice click to continue ");
	pIn->GetCellClicked();
	int playernum = pGrid->GetCurrentPlayer()->GetPlayerNum();
	if (playernum == 0) {
		playernum = 3;
	}

	else playernum = playernum - 1;
	pGrid->SetCurrPlayerNumber(playernum);

	pOut->ClearStatusBar();
}

void CardSeven::Save(ofstream &OutFile, ObjectType Type)  // Saves the GameObject parameters to the file
{

	if (Type == CARDSEVEN)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;

	}

}


void CardSeven::Load(ifstream &Infile, GameObject*p, Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	int cellnum;
	cardNumber = 7;
	Infile >> cellnum ;
	position = CellPosition::GetCellPositionFromNum(cellnum);
	
	pGrid->AddObjectToCell(p);

}



CardSeven::~CardSeven()
{
}


Card* CardSeven::GetCopy(CellPosition pos)
{
	return new CardSeven(pos);
}