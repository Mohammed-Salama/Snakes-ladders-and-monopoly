#include "Ladder.h"
#include "Snake.h"
#include"grid.h"
#include"cellposition.h"
#include<fstream>
#include <Windows.h>
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
}

Ladder::Ladder()
{

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	int x ,y;
	pIn->GetPointClicked(x , y);
	//Applying the ladder
	pGrid->UpdatePlayerCell( pPlayer,endCellPos );
	PlaySound("cheer", NULL, SND_SYNC);
	pOut->ClearStatusBar();
	

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

CellPosition Ladder::GetStartPosition() const
{
	return position;
}

void Ladder::Save(ofstream &OutFile,ObjectType Type)  // Saves the GameObject parameters to the file
{ 
	if(Type==LADDER)
	{
		OutFile<< position.GetCellNum() <<"  "<< endCellPos.GetCellNum() <<endl;

	}

}


void Ladder::Load(ifstream &Infile,GameObject*p,Grid*pGrid ) 	// Loads and Reads the GameObject parameters from the file
{
	int startcellnum, endcellnum;
	Infile >> startcellnum >> endcellnum;
	position = CellPosition::GetCellPositionFromNum(startcellnum);         //initailize gameObject class 
	endCellPos = CellPosition::GetCellPositionFromNum(endcellnum);          // initialize ladders & snakes & cards classes


	pGrid->AddObjectToCell(p);


}

Ladder::~Ladder()
{
}




bool Ladder::IsOverlapping(GameObject* newObj) const 
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

			if(!((StartCell2>EndCell1 && EndCell2>EndCell1) || (StartCell2< StartCell1 && EndCell2<StartCell1)) )

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


			if(EndCell1==StartCell2||EndCell2==StartCell1)
			{
				return true;
			}

		}
		

       return false;

	}

}

