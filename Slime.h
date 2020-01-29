#pragma once
#include "Enemy.h"


class Slime :public Enemy
{
private:



public:
	Slime();
	~Slime();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
};

