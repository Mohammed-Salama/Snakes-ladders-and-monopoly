#include "Player.h"
#include "ApplicationManager.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	freezed = false;
    debited = false;

	// Make all the needed initialization or validations
	AttackNumber = 0;
	cBurn = 0;      //means normally dont burn 
	cpoison = 0;   //means normally dont poison
	 Usedice=0;
	UsedFire=0;
	 UsedPoison=0;
	 UsedLight = 0;
	 nBurn=0;
	 nPoison=0;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}
void Player::SetTurnCount(int turn)
{
 turnCount=turn;
	
}
void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetPlayerNum() const
{
	return playerNum;
}
int Player::GetJustRolledDiceNum() const
{
	return justRolledDiceNum ;
}
int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::setFreezed(bool f)
{
	freezed = f;
}
void Player::setDebited(bool f)
{
	debited = f;
}
bool Player::getFreezed()
{
	return freezed;
}

void Player::SetAttackNumber(int a)
{
	 AttackNumber=a;
	
}
void Player::SetcBurn(int a)
{
	 cBurn=a;
	
}
void Player::SetnPoison(int a)
{
	 nPoison=a;
	
}
void Player::Setcpoison(int a)
{
	 cpoison=a;
	
}
void Player::SetUsedice(int a)
{
	 Usedice=a;
	
}
void Player::SetUsedFire(int a)
{
	 UsedFire=a;
	
}
void Player::SetnBurn(int a)
{
	 nBurn=a;
	
}
void Player::SetUsedPoison(int a)
{
	UsedPoison=a;
	
}
void Player::SetUsedLight(int a)
{
	UsedLight=a;
	
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	CellPosition cellPos;
	cellPos=pCell->GetCellPosition();
	pOut->DrawPlayer( cellPos, playerNum,  playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	CellPosition cellPos;
	cellPos=pCell->GetCellPosition();
	pOut->DrawPlayer( cellPos, playerNum,  cellColor);
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	
	// == Here are some guideline steps (numbered below) to implement this function ==
	if (pGrid->GetCurrentPlayer()->getFreezed())
	{
		 Output * pOut=pGrid->GetOutput();
		 Input* pIn = pGrid->GetInput();
		 pOut->PrintMessage("you are freezed for this turn and wont be able to roll the dice: Click to continue");
		 pIn->GetCellClicked();
		diceNumber = 0;
		pGrid->GetCurrentPlayer()->setFreezed(false);
	}

	////////////////////////////////////////////here are the added part for bonus////////////////////////////////////////////////
	if (cBurn != 0) {
		Output * pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("you are fired thus you wallet amount will decrease by" + to_string(nBurn* 20)+": Click to continue");
		pIn->GetCellClicked();
		wallet = wallet -(nBurn* 20);
		setburn(0,cBurn - nBurn);
	}
	else 
	{
		nBurn=0;
	}

	if (cpoison != 0) {
		Output * pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		int n=diceNumber-nPoison;
		if (n<0)
		{
			n=0;
		}
		pOut->PrintMessage("you are poisoned  thus your rolled dice was "+ to_string(diceNumber)+"but you will only move  " + to_string(n)+"  Click to continue");
		pIn->GetCellClicked();
		diceNumber=n;
		setpoison(0,cpoison - nPoison);
	}
	else
	{
		nPoison=0;
	}
	///////////////////////////////////////////////////////end of bonus part////////////////////////////////////////////////
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
		turnCount=turnCount+1;
		 
	if ((turnCount)%3 ==0 )
	{
		if (CanAttack(pGrid, diceNumber) == false) {
			Output* pOut = pGrid->GetOutput();
			pOut->PrintMessage("you wont be able to attack , thus your wallet amount will increase: click to continue");
			wallet = wallet + (10 * diceNumber);
		}
		return;
	}
	if (wallet <1)
	{
		return;
	}
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum=diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos;
	CellPosition lastpos;
	pos=pCell->GetCellPosition();
	
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
    Player * pPlayer;
	pPlayer=this;
	if (!debited)
	{
		pos.AddCellNum(diceNumber);
		pGrid->UpdatePlayerCell(pPlayer, pos);
	}
	// 6- Apply() the game object of the reached cell (if any)
	GameObject *gameopj;
	gameopj=pCell-> GetGameObject();
	

	CellPosition c1;
	c1=pCell->GetCellPosition();
	
	while (gameopj!=NULL)
	{
	
	Cell * c2 ;
	c2= pPlayer->GetCell();
		gameopj->Apply( pGrid,   pPlayer);
	
	pCell= pPlayer->GetCell();
	gameopj=pCell->GetGameObject();
	if (pCell->GetCellPosition().GetCellNum() ==c2->GetCellPosition().GetCellNum())
		break;
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	int cCellnum;
	cCellnum=pos.GetCellNum();
	if (cCellnum>=99 || cCellnum<0  )
	{
		pGrid->SetEndGame(true);
	}

	

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}




/////////////////////////////////////all that concerns the bonys part ////////////////////////////////////////////

bool Player::CanAttack(Grid * pGrid, int diceNumber) {
	Input *pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (diceNumber == 0 || AttackNumber >= 2|| AttackNumber < -1||wallet<1)       //to allow player to attack if he has attacknumber (2 choices only )
		return false;                                                   //and is not freezed(dicenumber=0)
	if (AttackNumber == 0)
		pOut->PrintMessage("Do you want to use your first attack ?    if yes insert (y) if no insert(n) and thus your wallet will be recharged");
	if (AttackNumber == 1)
		pOut->PrintMessage("Do you want to use your second attack ?    if yes insert (y) if no insert(n) and thus your wallet will be recharged");
	//the above 2 ifs prints message according to the number of attacks the player had used 
	// to use the first attack that means he consumed 0 attacknumber 
	 string  accept=pIn->GetSrting(pOut);
	 if (accept != "y") {
		 return false;
	 }                                                //that means he cant attack either he enterd n (no) or invalid word
	 pOut->PrintMessage(" to ice someone click 1 , to fire someone click 2 , to poison somone click 3 , to light all players click 4");
	 int numberchosen = pIn->GetInteger(pOut);

	 //uptill here if he could and accepted to attack he will choose his attack action

	 if (numberchosen == 1) {
		 if (Usedice==1) {
			 pOut->PrintMessage("you cant use same action twice ,thus you will be recharged and try next time to choose a unique action");
			 pIn->GetCellClicked();
			 return false;
		 }
		 pOut->PrintMessage("insert the player number you want to ice ");
		 int victimnumber = pIn->GetInteger(pOut);    //taking the player number needed to apply the action on it 
		 pOut->ClearStatusBar();
		 return  IceAction(pGrid, victimnumber);                                     //iceaction should be executed
	 }
	 if (numberchosen==2) {
		 if (UsedFire ==1) {
			 pOut->PrintMessage("you cant use same action twice ,thus you will be recharged and try next time to choose a unique action");
			 pIn->GetCellClicked();
			 return false;
		 }
		 pOut->PrintMessage("insert the player number you want to fire");
		 int victimnumber = pIn->GetInteger(pOut);    //taking the player number needed to apply the action on it 
		 pOut->ClearStatusBar();
		 return FireAction(pGrid,victimnumber);
       //fireaction should be executed
	 }
	 if (numberchosen==3) {
		 if (UsedPoison== 1) {
			 pOut->PrintMessage("you cant use same action twice ,thus you will be recharged and try next time to choose a unique action");
			 pIn->GetCellClicked();
			 return false;
		 }
		 pOut->PrintMessage("insert the player number you want to Poison");
		 int victimnumber = pIn->GetInteger(pOut);    //taking the player number needed to apply the action on it 
		 pOut->ClearStatusBar();
		 return PoisonAction(pGrid,victimnumber);
		 //poisonaction should be executed
	 }
	 if (numberchosen==4) {
		 if (UsedLight== 1) {
			 pOut->PrintMessage("you cant use same action twice ,thus you will be recharged and try next time to choose a unique action");
			 pIn->GetCellClicked();
			 return false;
		 }
		 return LightningAction(pGrid);
		 //lightaction should be executed
	 }
	 return false;                                     //he will not be able to attack if he enterd incorrrect number of attack action
}




bool Player::IceAction(Grid * pGrid, int n) {
	Output * pOut = pGrid->GetOutput();
	Input*pIn = pGrid->GetInput();
	Player *p = pGrid->GetCurrentPlayer();
	if ( pGrid->GetPlayerFromNum(n))
	{
	Player *victim = pGrid->GetPlayerFromNum(n);
	if (p->GetPlayerNum() == victim->GetPlayerNum()) {
		pOut->PrintMessage("you can't Attack yourself : click to continue");
		pIn->GetCellClicked();
		return false;
	}
	else {
		victim->setFreezed(true);
		AttackNumber++;
		Usedice++;
		return true;
	}
	}
}


bool Player::FireAction(Grid * pGrid, int n) {
	Output * pOut = pGrid->GetOutput();
	Input*pIn = pGrid->GetInput();
	Player *p = pGrid->GetCurrentPlayer();
	if ( pGrid->GetPlayerFromNum(n))
	{
	Player *victim = pGrid->GetPlayerFromNum(n);
	if (p->GetPlayerNum() == victim->GetPlayerNum()) {
		pOut->PrintMessage("you can't Attack yourself : click to continue");
		pIn->GetCellClicked();
		return false;
	}
	else {
		victim->setburn(3,0);
		AttackNumber++;
		UsedFire++;
		return true;
	}
	}

}

void Player::setburn(int b , int c ) {
	
	if (b!=0) {
		cBurn =cBurn + b;
		nBurn=nBurn+1;
	}
	else if (c!=0)
	{ 
		cBurn=c;
	}
	else cBurn = 0;      //which means dont burn , but if burn =2 means  he will be burned for 2 terms
}


bool Player::PoisonAction(Grid * pGrid, int n) {
	Output * pOut = pGrid->GetOutput();
	Input*pIn = pGrid->GetInput();
	Player *p = pGrid->GetCurrentPlayer();
	if (pGrid->GetPlayerFromNum(n))
	{
	Player *victim = pGrid->GetPlayerFromNum(n);
	if (p->GetPlayerNum() == victim->GetPlayerNum()) {
		pOut->PrintMessage("you can't Attack yourself: Click to continue");
		pIn->GetCellClicked();
		return false;
	}
	else {
		victim->setpoison(5 , 0);
		AttackNumber++;
		UsedPoison++;
		return true;
	}
	}
}



void Player::setpoison(int p , int w) {
	
		if (p!=0)
		{
		cpoison =cpoison+ p;
		nPoison=nPoison+1;
		}
	

	else if (w!=0) 
	{
		cpoison = w;
	}
	else 
		cpoison=0;
}


bool  Player::LightningAction(Grid * pGrid) {
	Output * pOut = pGrid->GetOutput();
	Input*pIn = pGrid->GetInput();
	Player *p = pGrid->GetCurrentPlayer();
	p->SetWallet(p->GetWallet() + 20);
	pOut->PrintMessage("All Other players  wallet will be decreased by 20 : Click to continue");
	for (int i = 0; i < MaxPlayerCount; i++) {
		
		
		int newWallet = (pGrid->GetPlayerFromNum(i)->GetWallet()) - 20;        //loop for all players including the one who asked for attack to deduct 20 from their wallet 
		pGrid->GetPlayerFromNum(i)->SetWallet(newWallet);  
		
		//the main player will be increased by 20 latter to counter the effect
	}
	UsedLight++;
	AttackNumber++;
	pIn->GetCellClicked();
	return true;
}
