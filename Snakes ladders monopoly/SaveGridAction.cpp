#include "SaveGridAction.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include<fstream>
#include"Snake.h"

SaveGridAction::SaveGridAction(ApplicationManager *pApp): Action(pApp)
{

}


 void SaveGridAction::ReadActionParameters()
{
	 pGrid = pManager->GetGrid();
	 pOut = pGrid->GetOutput();
	 pIn = pGrid->GetInput();

	 pOut->PrintMessage("ENTER THE FILE NAME");
	 filename=pIn->GetSrting(pOut);
	 pOut->PrintMessage(filename);

}

SaveGridAction::~SaveGridAction()
{


}


 void SaveGridAction::Execute()
{
	

	ReadActionParameters();
	OutFile.open(filename, ios::out);

	OutFile<<pGrid->GetLadderNum()<<endl;
	pGrid->SaveAll(OutFile,LADDER);                      // save ladders
	OutFile<<pGrid->GetSnakeNum()<<endl; 
	pGrid->SaveAll(OutFile,SNAKE);                       // save snakes
	OutFile<<pGrid->GetCardNum()<<endl;

	for (int i = CARDONE;i != LAST;i++)
	{
		pGrid->SaveAll(OutFile, (ObjectType)i );         // CARDS IN FORLOOP 
	}

	
	OutFile.close();
    

	
}