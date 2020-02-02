#pragma once
#include "Enemy.h"




class Flower :public Enemy
{
private:
	RECT rc;
	int count;
	bool _up;
	bool left;
	bool right;
	bool atk, atkL, atkR;
	bool idle1;
	
public:
	Flower();
	~Flower();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void moving();
	virtual void F_state();
	virtual void attack();

	virtual void render();
	void hit();
	void die();
};
