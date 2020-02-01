#pragma once
#include"Sword.h"
#include"Ring.h"
#include"Coin.h"
#include"Armor.h"
#include"Potion.h"
typedef void(ItemManager::*_cbFunction)(ItemKinds, POINT);
class ItemManager:public singletonBase<ItemManager>
{
private :
	vector<Item*> _vItem;
	vector<Item*>::iterator _viItem;

public:
	ItemManager();
	~ItemManager();

	HRESULT init();
	void release();
	void makeItem(ItemKinds ins, POINT center);
	void eraseItem(GameObject* ins);
};

