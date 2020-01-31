#pragma once
#include"Enemy.h"
class Rabbit :public Enemy
{
	
	int count;
	int Movecheck;

	RECT rc;


public:
	Rabbit();
	~Rabbit();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	void moving();
	void attack();
	void hit();

	void trace();

	void Collision();

	void R_state();
	void R_control();
};

