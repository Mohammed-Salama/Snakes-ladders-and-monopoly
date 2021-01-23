#pragma once

#include "GameObject.h"


class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"
	CellPosition startCellPos;
	CellPosition endCellPos; // here is the ladder's End Cell Position

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	Ladder();

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer) override; // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	CellPosition GetStartPosition() const; // A getter for the startCellPos data member //added 

	virtual void Save(ofstream &OutFile,ObjectType Type) override ;	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile,GameObject*p,Grid*pGrid)override ;	// Loads and Reads the GameObject parameters from the file

	bool IsOverlapping(GameObject* newObj) const override;

	


	virtual ~Ladder(); // Virtual destructor
};

