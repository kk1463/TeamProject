#pragma once
#include "Enemy.h"


class Slime :public Enemy
{
private:



public:
	Slime();
	~Slime();
	virtual HRESULT init(POINT pos, int fps, float SPEED);
	virtual void release();
	virtual void update();
};

