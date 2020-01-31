#pragma once
#include"Item.h"

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
	void setItemVector(GameObject* ins);
};

