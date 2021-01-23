#pragma once
#include "Card.h"
#include"GameObject.h"
#include"Player.h"
#include"Card.h"
#include<iostream>
using namespace std;
class Player;
class CardTherteen :
	public Card
{
	
	static int cardPrice;
	static int fees;
	static Player* owner;
	static bool isFirst;
	bool added;
	// freezed players
	Player* Fvistor1 ;
	Player* Fvistor2 ;
	Player* Fvistor3 ;
	// they debite to the owner
	int Debited1 ;
	int Debited2 ;
	int Debited3 ;
public:
	CardTherteen(const CellPosition& pos);
	CardTherteen();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void SetBool();
	virtual void Save(ofstream& OutFile, ObjectType Type) override;	// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile, GameObject* p, Grid* pGrid) override;	// Loads and Reads the GameObject parameters from the file
	bool getadded();
	virtual Card* GetCopy(CellPosition pos);
	~CardTherteen();
};