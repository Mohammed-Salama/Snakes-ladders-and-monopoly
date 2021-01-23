#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}



 bool GameObject::IsOverlapping(GameObject* newObj) const 
 {
	 return false;
 }


GameObject::GameObject()
{

}