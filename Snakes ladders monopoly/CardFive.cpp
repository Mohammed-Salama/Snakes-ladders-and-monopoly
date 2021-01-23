#include "CardFive.h"



CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5;    // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::CardFive()
{

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("this card moves you the same steps you moved which is :" +to_string(pPlayer->GetJustRolledDiceNum()) + "  click to continue") ;
	Input * pIn = pGrid->GetInput();
	pIn->GetCellClicked();
	int movement = pPlayer->GetJustRolledDiceNum();      //takes the number of steps just moved and  makes the player remove again
	 int turn = pPlayer->GetTurnCount();   // modifying the trun count before enterig the move function 
	 turn--;
	 pPlayer->SetTurnCount(turn);
	 pPlayer->Move(pGrid, movement);
	 if (pPlayer->GetCell()->HasLadder()) {
		 pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);    //checks if there is ladder in the cell to take it 
	}
	 else if (pPlayer->GetCell()->HasSnake()) {
		 pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);     //chekcs if there is snake  in the cell to take it 
	 }
	pOut->ClearStatusBar();
 }



CardFive::~CardFive()
{
}


void CardFive::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file

 {
	 if(Type==CARDFIVE)
	 {
		 OutFile<<cardNumber<<"\t"<<position.GetCellNum()<<endl;
		 
	 }
	 

}


 void CardFive::Load(ifstream &Infile,GameObject*p,Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	 int cellnum;
	 cardNumber = 5;
	 Infile >> cellnum;
	 position = CellPosition::GetCellPositionFromNum(cellnum);

	pGrid->AddObjectToCell(p);
}

 Card* CardFive::GetCopy(CellPosition pos)
{
		return new CardFive(pos);
}
