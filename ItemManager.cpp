#include "stdafx.h"
#include "ItemManager.h"


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

void ItemManager::setItemVector(GameObject * ins)
{
	_vItem.push_back((Item*)ins);
}
