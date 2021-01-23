#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager *pApp): Action(pApp)
{

}


SwitchToDesignModeAction::~SwitchToDesignModeAction()
{
}

void SwitchToDesignModeAction::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	pOut->CreateDesignModeToolBar();
}

void SwitchToDesignModeAction::ReadActionParameters()
{
}