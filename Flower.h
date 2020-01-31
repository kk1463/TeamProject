#pragma once
#include "Enemy.h"




class Flower :public Enemy
{
private:
	RECT rc, atkL, atkR;
	int count;
	bool _up;
	bool left;
	bool right;
	bool atk;

public:
	Flower();
	~Flower();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void moving();
	virtual void F_state();
};
