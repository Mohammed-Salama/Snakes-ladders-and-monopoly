#pragma once
#include "gameobject.h"
#include<fstream>
class Snake : public GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the snake's "Start Cell Position"
	CellPosition startCellPos;
	CellPosition endCellPos; // here is the snake's End Cell Position

	

public:


	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	Snake();

	 void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	 void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	CellPosition GetStartPosition()const;//a getter for the startCellPos data member
    //int GetSnakeNum();

	 virtual void Save(ofstream &OutFile,ObjectType Type) override  ;	// Saves the GameObject parameters to the file
	 void Load(ifstream &Infile,GameObject*p,Grid*pGrid)override ;	// Loads and Reads the GameObject parameters from the file

	 bool IsOverlapping(GameObject* newObj) const override;

	 ~Snake(); // Virtual destructor
	 
	

};

