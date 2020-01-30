#pragma once
#include"Enemy.h"
class Rabbit:public Enemy
{
	bool move;
	bool atk;
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


	void Collision();

	void R_state();
	void R_control();
};

