#pragma once
#include "Card.h"
class CardFour :public Card
{
public:
	CardFour();
	CardFour(const CellPosition & pos); // A Constructor takes card position
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
	virtual void Save(ofstream &OutFile, ObjectType Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, GameObject*p, Grid*pGrid);	// Loads and Reads the GameObject parameters from the file
	virtual Card* GetCopy (CellPosition pos);
	
	~CardFour();
};

