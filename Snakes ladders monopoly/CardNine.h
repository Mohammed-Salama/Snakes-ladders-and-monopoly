#pragma once
#include "Card.h"
class CardNine :
	public Card
{
	CellPosition cpos;
	int  cellnumber;  // data member  that will be read from the user 
public:
	CardNine();
	CardNine(const CellPosition & pos); // A Constructor takes card position
	
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardNine which is: cell needed to move to 
	virtual void Save(ofstream &OutFile, ObjectType Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, GameObject*p, Grid*pGrid);	// Loads and Reads the GameObject parameters from the file

	CardNine(CellPosition pos,int n);
	virtual Card* GetCopy (CellPosition pos);
	
	~CardNine();
};

