#include "DeleteGameOpject.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "gameobject.h"
DeleteGameOpject::DeleteGameOpject(ApplicationManager *pApp): Action(pApp)
{

}
void DeleteGameOpject::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete Object: Click on its Start Cell ...");
	OpjCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void DeleteGameOpject::Execute() 
{
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();
	//Remove the opject from the game
	 pGrid->RemoveObjectFromCell(OpjCell);
}
DeleteGameOpject::~DeleteGameOpject()
{
}
