#pragma once
#include "Enemy.h"

class Flower :public Enemy
{
private:


public:
	Flower();
	~Flower();
	virtual HRESULT init(POINT pos, int fps, float SPEED);
	virtual void release();
	virtual void update();
};
