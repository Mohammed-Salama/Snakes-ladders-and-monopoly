#include "CardSix.h"


CardSix::CardSix()
{
}

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number ( 6 here)
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)                       // Applies the effect of CardSix on the passed Player
{
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("this card moves you backwards the same steps you moved which is :" + to_string(pPlayer->GetJustRolledDiceNum()) + "  click to continue");
	Input * pIn = pGrid->GetInput();
	pIn->GetCellClicked();
	int turn = pPlayer->GetTurnCount();   // modifying the trun count before enterig the move function 
	turn--;
	pPlayer->SetTurnCount(turn);
	int movement = - (pPlayer->GetJustRolledDiceNum());                //moves the player backwards the same steps he has just moved 
	pPlayer->Move(pGrid, movement);
	pOut->ClearStatusBar();
}



CardSix::~CardSix()
{
}


void CardSix::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file
{

	if(Type==CARDSIX)
	 {
		 OutFile<<cardNumber<<"\t"<<position.GetCellNum()<<endl;
		 
	 }
	

}


 void CardSix::Load(ifstream &Infile,GameObject*p,Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	 int cellnum;
	 cardNumber = 6;
	 Infile >> cellnum;
	 position = CellPosition::GetCellPositionFromNum(cellnum);

	pGrid->AddObjectToCell(p);
	 
}

 Card* CardSix::GetCopy(CellPosition pos)
{
	return new CardSix(pos);
}