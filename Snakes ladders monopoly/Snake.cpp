#include "Snake.h"
#include"ladder.h"

#include <Mmsystem.h>
#include <mciapi.h>   //these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")
#include<Windows.h>
#include<iostream>
using namespace std;

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	this->startCellPos = startCellPos;
}
void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
	
}
Snake::Snake()
{

}

void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	int x ,y;
	pIn->GetPointClicked(x , y);
	//Apllying the snake
	pGrid->UpdatePlayerCell( pPlayer,endCellPos );
	PlaySound("door_knob", NULL, SND_SYNC);

	pOut->ClearStatusBar();
	
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}



CellPosition Snake::GetStartPosition()const
{
	return  position ;
}
void Snake::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file

 {
	 if(Type==SNAKE)
	 {
		 OutFile<< position.GetCellNum() <<"  "<< endCellPos.GetCellNum() <<endl;
		 
	 }

}


 void Snake::Load(ifstream &Infile,GameObject*p,Grid*pGrid) 	// Loads and Reads the GameObject parameters from the file
{
	 int startcellnum, endcellnum;
	 Infile >> startcellnum >> endcellnum;
	 position = CellPosition::GetCellPositionFromNum(startcellnum);         //initailize gameObject class 
	 endCellPos = CellPosition::GetCellPositionFromNum(endcellnum);          // initialize ladders & snakes & cards classes
	 pGrid->AddObjectToCell(p);
}


Snake::~Snake(void)
{
}




bool Snake::IsOverlapping(GameObject* newObj) const 
{
	if(this==newObj)
		return false;
	if(dynamic_cast<Ladder*>(newObj))
	{
		int h1=position.HCell();
		int h2=newObj->GetPosition().HCell();

		if(h1==h2)
		{

			int StartCell1=CellPosition::GetCellNumFromPosition(position);
			int EndCell1=CellPosition::GetCellNumFromPosition(endCellPos);

			Ladder* pladder=(Ladder*)newObj;

			int StartCell2=CellPosition::GetCellNumFromPosition(newObj->GetPosition());
			int EndCell2=CellPosition::GetCellNumFromPosition(pladder->GetEndPosition());

			if(EndCell1 == StartCell2 || EndCell2 == StartCell1)

			{
				return true;
			}
		}

		return false;
	}


	
	if(dynamic_cast<Snake*>(newObj))
	{
		int h1=position.HCell();
		int h2=newObj->GetPosition().HCell();

		if(h1==h2)
		{
			int StartCell1=CellPosition::GetCellNumFromPosition(position);
			int EndCell1=CellPosition::GetCellNumFromPosition(endCellPos);

			Snake * psnake=(Snake*)newObj;

			int StartCell2=CellPosition::GetCellNumFromPosition(newObj->GetPosition());
			int EndCell2=CellPosition::GetCellNumFromPosition(psnake->GetEndPosition());


			if(!((StartCell2>StartCell1 && EndCell2>StartCell1) || (StartCell2< EndCell1 && EndCell2<EndCell1)))
			{
				return true;
			}

		}
		

       return false;

	}

}
