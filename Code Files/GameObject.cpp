#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

GameObject::GameObject()
{
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

ObjectType GameObject::getObjectType()
{

	return type;
}

bool GameObject::IsOverlapping(GameObject* newObj) const
{
	return false;
}

GameObject::~GameObject()
{
}