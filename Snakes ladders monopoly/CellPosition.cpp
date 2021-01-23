#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition ()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition (int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	// by Mohamed
	if (v>=0 && v<9)
	{
		vCell = v;
		return true;
	}
	else
		
	{	
		vCell=-1;
	                    
	return false;
	}

	// this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	if (h>=0 && h<11)
	{
		hCell = h;
		return true;
	}
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	else
		
	{	
		hCell=-1;
	                    
	return false;
	} // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if (vCell>=0 && vCell<9 && hCell>=0 && hCell<11 )
	{
		return true;
	}
	///TODO: Implement this function as described in the .h file
	else

	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{

	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	int V;
	int H;
	V=cellPosition.VCell();
	H=cellPosition.HCell ();
	int Num;
	Num = ((8-V)*11)+ ( H +1);
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file



	return Num ; // this line should be changed with your implementation
}



CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{

	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	int  a;
	a=cellNum;
	if (a<1 || a>99)
	{
	position.vCell = -1;
	position.hCell = -1;
	return position;
	}
	position.vCell = 8- ((a-1)/11);
	position.hCell = ((a-1) % 11) ;


	/// TODO: Implement this function as described in the .h file



	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	CellPosition c;
	int b;
	b=GetCellNum();
	b=b+addedNum;
	c=GetCellPositionFromNum(b);
	int v ;
	int h ;
	v=c.vCell;
	h=c.hCell;
	SetVCell( v);
	SetHCell(h);
	//int f;

	//f =GetCellNumFromPosition(c);

	/// TODO: Implement this function as described in the .h file



	// Note: this function updates the data members (vCell and hCell) of the calling object

}
