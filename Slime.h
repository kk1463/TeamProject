#pragma once
#include "Enemy.h"



class Slime :public Enemy
{
private:


	int count;

public:
	Slime();
	~Slime();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	void S_Collision();
	void S_moving();
	void S_state();
	void S_attack();
	void S_hit();
	void S_die();
	void S_trace();
};

