#include "LoadGridAction.h"
#include"Cellposition.h"
#include"cardone.h"
#include"cardtwo.h"
#include"cardthree.h"
#include"cardfour.h"
#include"cardFive.h"
#include"cardSix.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardSeven.h"
#include"Cardten.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardTherteen.h"
#include"CardFourteen.h"



LoadGridAction::LoadGridAction(ApplicationManager *pApp): Action(pApp)
{
	int ladderNum=0;
	int snakeNum=0;
	int numberofcards=0;


}

LoadGridAction::~LoadGridAction()
{

}

void LoadGridAction::ReadActionParameters()
{
	pGrid = pManager->GetGrid();
	pOut = pGrid->GetOutput();
	pIn = pGrid->GetInput();

	pOut->PrintMessage("ENTER THE FILE NAME");
	filename=pIn->GetSrting(pOut);
	pOut->PrintMessage(filename);


}

void LoadGridAction::Execute()
{
	ReadActionParameters();

	//int startcellnum,endcellnum;
	CellPosition startposition,endposition;


	ifstream Infile(filename);

	if (Infile.is_open())
	{
		Infile >> ladderNum;

		for(int i=0;i<ladderNum;i++)
		{
			GameObject*Pladder=new Ladder();
			
			Pladder->Load(Infile,Pladder,pGrid);

		}

		Infile >> snakeNum;

		for(int i=0;i<snakeNum;i++)
		{
			GameObject*Psnake=new Snake();
			
			Psnake->Load(Infile,Psnake,pGrid);

		}

		Infile >> numberofcards;

		for(int i=0;i<numberofcards;i++)
		{
			Infile >>cardtype;

			switch (cardtype)
			{

			case 1:
				{


					GameObject*PCardOne=new CardOne();
					
					PCardOne->Load(Infile,PCardOne,pGrid);


				}
				break;

			case 2:
				{


					GameObject*PCardTwo=new CardTwo();
					
					PCardTwo->Load(Infile,PCardTwo,pGrid);


				}
				break;
			case 3:
			{


				GameObject* PCardThree = new CardThree();
				
				PCardThree->Load(Infile, PCardThree, pGrid);


			}
				break;
			case 4:
			{


				GameObject* PCardFour = new CardFour();
				
				PCardFour->Load(Infile, PCardFour, pGrid);


			}
			break;

				case 5:
				{


					GameObject*PCardFive=new CardFive();
					
					PCardFive->Load(Infile,PCardFive,pGrid);                                    //////////////////////////////////////// paste action //////////////////////////////////


				}
				break;

				case 6:
				{


					GameObject*PCardSix=new CardSix();
					
					PCardSix->Load(Infile,PCardSix,pGrid);


				}
				break;

				case 7:
				{


					GameObject* PCardSeven = new CardSeven();

					PCardSeven->Load(Infile, PCardSeven, pGrid);


				}
				break;




				case 8:
				{


					GameObject* PCardEight = new CardEight();

					PCardEight->Load(Infile, PCardEight, pGrid);


				}
				break;


				case 9:
				{


					GameObject* PCardNine = new CardNine();

					PCardNine->Load(Infile, PCardNine, pGrid);


				}
				break;

				case 10:
				{


					GameObject* PCardTen = new CardTen();

					PCardTen->Load(Infile, PCardTen, pGrid);


				}
				break;

				case 11:
				{


					GameObject* PCardEleven = new CardEleven();

					PCardEleven->Load(Infile, PCardEleven, pGrid);


				}
				break;

				case 12:
				{


					GameObject* PCardTwelve = new CardTwelve();

					PCardTwelve->Load(Infile, PCardTwelve, pGrid);


				}
				break;
				case 13:
				{


					GameObject* PCardTherteen = new CardTherteen();

					PCardTherteen->Load(Infile, PCardTherteen, pGrid);


				}
				break;
				case 14:
				{


					GameObject* PCardFourteen = new CardFourteen();

					PCardFourteen->Load(Infile, PCardFourteen, pGrid);


				}
				break;

				// TODO: add more cases for other types


			}

		}





		Infile.close();
	}



}
