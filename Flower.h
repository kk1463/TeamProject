#pragma once
#include "Enemy.h"




class Flower :public Enemy
{
private:


public:
	Flower();
	~Flower();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
};
