#pragma once
#include "Enemy.h"



class Slime :public Enemy
{
private:



	bool move;
	bool atk;
	int count;
	int Movecheck;

public:
	Slime();
	~Slime();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	void collision();
	void S_move();
	void S_state();
};

