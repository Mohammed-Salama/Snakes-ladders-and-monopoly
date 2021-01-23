#include "CardTen.h"
#include "GameObject.h"
using namespace std;
#include <iostream>
//initialization for static data members
bool CardTen::isFirst = true;
Player* CardTen::owner = NULL;
int CardTen::cardPrice = 0;
int CardTen::fees = 0;
//constructor
CardTen::CardTen(const CellPosition& pos) : Card(pos)
{
	cardNumber = 10;
	bool added= true;
	Player* Fvistor1 = NULL;
	Player* Fvistor2 = NULL;
	Player* Fvistor3 = NULL;
	// they debite to the owner
	int Debited1 = 0;
	int Debited2 = 0;
	int Debited3 = 0;
}

bool CardTen::getadded() {
	return added;
}

CardTen::CardTen()
{

}
//reading prameters from the user if it is the first time
void CardTen::ReadCardParameters(Grid* pGrid)
{
	if (isFirst)
	{
		pGrid->GetOutput()->PrintMessage("please enter card price");
		int cp = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
		if (cp > 0)
			cardPrice = cp;
		else
		{
			added = false;
			return;
		}
		(pGrid->GetOutput())->PrintMessage("please enter the fees");
		int f= (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
		if (f > 0)
			fees = f;
		else
		{
			added = false;
			return;
		}

	    isFirst = false;
	}
}
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int wallet = pPlayer->GetWallet();
	string choice;
	//Offerring to buy all cells that has card 10
	if (owner == NULL)
	{
		pOut->PrintMessage("this cell costs " + to_string(cardPrice) + " do you want to buy it ? enter y or n");
		choice = pIn->GetSrting(pOut);

		if (choice == "y")
		{
			if (wallet < cardPrice)
			{
				pOut->PrintMessage("sorry, you have insufficiant amount of money ,click to continue... ");
			}
			else
			{
				pPlayer->SetWallet(wallet -= cardPrice);
				owner = pGrid->GetCurrentPlayer();
				pOut->PrintMessage("congratulations, you now own all  the cells that has card 10 ,click to continue...");
			}
		}
		else
			pOut->PrintMessage("click to continue... ");
	}
	else
	{
		//vistor pays fees to owner
		if (pPlayer != owner)
		{

			if (pPlayer != Fvistor1 && pPlayer != Fvistor2 && pPlayer != Fvistor3)
			{
				pOut->PrintMessage("you are a visitor in the property of player " + to_string(owner->GetPlayerNum()) + " you should pay him " + to_string(fees) + " click to continue...");
				pIn->GetCellClicked();
				if (wallet < fees)
				{
					pOut->PrintMessage("you have insufficiant amount of money :you will freeze till you have enough to move ,click to continue... ");
					pPlayer->SetWallet(0);
					pPlayer->setDebited(true);
					if (Fvistor1 == NULL)
					{
						Debited1 = fees - wallet;
						Fvistor1 = pPlayer;
					}
					else if (Fvistor2 == NULL)
					{
						Debited2 = fees - wallet;
						Fvistor2 = pPlayer;
					}
					else
					{
						Debited3 = fees - wallet;
						Fvistor3 = pPlayer;
					}
				}
				else
				{
					pPlayer->SetWallet(wallet -= fees);
					owner->SetWallet(owner->GetWallet() + fees);
				}
			}
			else if (pPlayer == Fvistor1)
			{
				if (wallet < Debited1)
				{
					pOut->PrintMessage("you still have insufficiant amount of money :you will freeze till you have enough to move ,click to continue... ");
					pPlayer->SetWallet(0);
					pPlayer->setDebited(true);
					Debited1 = Debited1 - wallet;
					Fvistor1 = pPlayer;
				}
				else
				{
					pOut->PrintMessage("you payed the fees , you can move now ,click to continue... ");
					pPlayer->SetWallet(wallet - Debited1);
					owner->SetWallet(owner->GetWallet() + fees);
					pPlayer->setDebited(false);
					Debited1 = 0;
					int realTurnCount = pPlayer->GetTurnCount();
					pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNum());
					Fvistor1 = NULL;
					pPlayer->SetTurnCount(realTurnCount);
				}

			}
			else if (pPlayer == Fvistor2)
			{
				if (wallet < Debited2)
				{
					pOut->PrintMessage("you still have insufficiant amount of money :you will freeze till you have enough to move ,click to continue... ");
					pPlayer->SetWallet(0);
					pPlayer->setDebited(true);
					Debited2 = Debited2 - wallet;
					Fvistor2 = pPlayer;
				}
				else
				{
					pOut->PrintMessage("you payed the fees , you can move now ,click to continue... ");
					pPlayer->SetWallet(wallet - Debited2);
					owner->SetWallet(owner->GetWallet() + fees);
					pPlayer->setDebited(false);
					Debited2 = 0;
					int realTurnCount = pPlayer->GetTurnCount();
					pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNum());
					Fvistor2 = NULL;
					pPlayer->SetTurnCount(realTurnCount);
				}
			}
			else
			{
				if (wallet < Debited3)
				{
					pOut->PrintMessage("you still have insufficiant amount of money :you will freeze till you have enough to move ,click to continue... ");
					pPlayer->SetWallet(0);
					pPlayer->setDebited(true);
					Debited3 = Debited3 - wallet;
					Fvistor3 = pPlayer;
				}
				else
				{
					pOut->PrintMessage("you payed the fees , you can move now ,click to continue... ");
					pPlayer->SetWallet(wallet - Debited3);
					owner->SetWallet(owner->GetWallet() + fees);
					pPlayer->setDebited(false);
					Debited3 = 0;
					int realTurnCount = pPlayer->GetTurnCount();
					pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNum());
					Fvistor3 = NULL;
					pPlayer->SetTurnCount(realTurnCount);
				}
			}
		}
		else
		{
			pOut->PrintMessage("welcome in your home ,click to continue... ");

		}
	}
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
// to edit card
void CardTen::SetBool()
{
	isFirst = true;
}
Card* CardTen::GetCopy(CellPosition pos)
{
	return new  CardTen (pos);
}
CardTen::~CardTen()
{

}
void CardTen::Save(ofstream& OutFile, ObjectType Type)  // Saves the GameObject parameters to the file
{
	if (Type == CARDTEN)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << "\t" << cardPrice << "\t" << fees << endl;

	}


}


void CardTen::Load(ifstream& Infile, GameObject* p, Grid* pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	int cellnum;
	cardNumber = 10;
	Infile >> cellnum >> cardPrice >> fees;
	position = CellPosition::GetCellPositionFromNum(cellnum);
	bool added = true;
	Player* Fvistor1 = NULL;
	Player* Fvistor2 = NULL;
	Player* Fvistor3 = NULL;
	// they debite to the owner
	int Debited1 = 0;
	int Debited2 = 0;
	int Debited3 = 0;

	pGrid->AddObjectToCell(p);


}
