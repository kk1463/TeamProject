#include "stdafx.h"
#include "ItemManager.h"
#include"gameNode.h"

ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}

HRESULT ItemManager::init()
{

	return S_OK;
}

void ItemManager::release()
{
}

void ItemManager::makeItem(ItemKinds ins,POINT center)
{
	GameObject* container = NULL;
	switch (ins)
	{
	case SWORD:
		container = new Sword;
		break;
	case ARMOR:
		container = new Armor;
		break;
	case RING:
		container = new Ring;
		break;
	case COIN:
		container = new Coin;
		break;
	case POTION:
		container = new Potion;
		break;
	case SHIELD:
		break;
	default:
		break;
	}
	((Item*)container)->init(std::move(center));
	
	_vItem.push_back((Item*)ins);
	SCENEMANAGER->getCurrentScene()->setGameObj(container);
}

void ItemManager::eraseItem(GameObject * ins)
{
	_viItem = _vItem.begin();
	for (; _viItem != _vItem.end();)
	{
		GameObject* temp = *_viItem;
		if (temp == ins)
		{
			_vItem.erase(_viItem);
			SCENEMANAGER->getCurrentScene()->deleteObject(ins);
			break;
		}
		else ++_viItem;

	}
}
