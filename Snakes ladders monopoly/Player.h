#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	bool freezed;
	bool debited;

	/////////////////////starting from here: all that concers the bonus part////////////////////////////////////////////

	int AttackNumber;
	int cBurn;    //burn for 3 turns 
	int  cpoison;  //posion for 5 consecutive turns (deduct 1 value from dice number)
	int Usedice;
	int UsedFire;
	int UsedPoison;
	int UsedLight;
	int nBurn;
	int nPoison;
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);	
    void SetTurnCount(int turn);			// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell
	void SetStepCount(int stcount);
	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet
	int GetPlayerNum() const;
	int GetJustRolledDiceNum() const;
	int GetTurnCount() const;		// A getter for the turnCount
	void setFreezed(bool f);
	bool getFreezed();
	void setDebited(bool d);
	void SetAttackNumber(int a);
	void SetcBurn(int a);
	void SetnBurn(int a);
	void Setcpoison(int a);
	void SetnPoison(int a);
	void SetUsedice(int a);
	void SetUsedPoison(int a);
	void SetUsedLight(int a);
	void SetUsedFire(int a);
	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)




	/////////////////////starting from here all that concerns the bonus part////////////////////////////////////
	bool CanAttack(Grid * pGrid, int diceNumber);
	bool IceAction(Grid * pGrid, int n);              //n here represents the player number which was chosen to  be attacked
	bool FireAction(Grid * pGrid, int n);
	void setburn(int b , int c);
	bool PoisonAction(Grid * pGrid, int n);
	void setpoison(int p ,int w);
	bool LightningAction(Grid * pGrid);
};

