#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update()
{
}

HRESULT GameObject::init()
{
	//cout << "GameObjectInit" << endl;
	switch (_kinds)
	{
	case HYDRA:
		_image = IMAGEMANAGER->findImage("Hydra");
		break;
	case RABBIT:
		_image = IMAGEMANAGER->findImage("Rabbit");
		break;
	case FLOWER:
		_image = IMAGEMANAGER->findImage("Flower");
		break;
	case SLIME:
		_image = IMAGEMANAGER->findImage("Slime");
		break;
	case PLAYER:
		break;
	case OBJ_NONE:
		break;
	default:
		break;
	}
	return S_OK;
}

HRESULT GameObject::init(POINT pos, int fps, float SPEED)
{
	return S_OK;
}

void GameObject::attaked(int atk)
{

}

void GameObject::render()
{
}


