#pragma once
#include "Card.h"
#include "Card.h"
#include"CellPosition.h"

// Its Apply() Function: increments the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to increase --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo : public Card
{
	 bool  added;
	int  walletAmount;
	bool isFirst;
public:
	CardTwo(const CellPosition & pos);  // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardTwo which is: walletAmount
	bool getadded();
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player  // by incrementing the player's wallet by the walletAmount data member
	CardTwo();
	
	virtual void Save(ofstream &OutFile,ObjectType Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile,GameObject*p,Grid*pGrid) ;	// Loads and Reads the GameObject parameters from the file


	CardTwo(CellPosition pos ,int w);
	virtual Card* GetCopy (CellPosition pos);

	virtual~CardTwo();
};

