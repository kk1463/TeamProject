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
	ItemKinds _kinds;
public:
	Item();
	~Item();
};

