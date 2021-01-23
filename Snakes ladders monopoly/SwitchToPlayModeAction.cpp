#include "SwitchToPlayModeAction.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager *pApp): Action(pApp)
{

}


SwitchToPlayModeAction::~SwitchToPlayModeAction()
{
}

void SwitchToPlayModeAction::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	pOut->CreatePlayModeToolBar();
}

void SwitchToPlayModeAction::ReadActionParameters()
{
}