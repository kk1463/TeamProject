#pragma once
#include"Item.h"
class Sword:public Item
{
public:
	Sword();
	~Sword();

	virtual void collide();
};

