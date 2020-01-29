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
	virtual HRESULT init(POINT pos, int fps, float SPEED);
	virtual void release();
	virtual void update();
	void moving();
	void attack();




	void R_state();
	void R_control();
};

