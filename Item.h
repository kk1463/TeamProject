#pragma once
#include"GameObject.h"
enum ItemKinds
{
	SWORD,
	ARMOR,
	RING,
	COIN,
	POTION,
	SHIELD
};
class Item:public GameObject
{
protected:
	ItemKinds _itemKinds;
public:
	Item();
	~Item();
	void init(POINT ins);
};

