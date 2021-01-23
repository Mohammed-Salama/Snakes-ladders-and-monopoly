#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

Card::Card()
{

}


bool Card::getadded() {
	return true;
}
void Card::SetBool()
{

}
void Card::SetCardNumber(int cnum)
{
	if (cnum < 15 && cnum>0) {
		cardNumber = cnum;
	}
	else cardNumber = -1;// needs validation
}
int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw( Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"


}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card::~Card()
{
}


void Card::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file

 {
	

}


 void Card::Load(ifstream &Infile,GameObject*p,Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	
}

 