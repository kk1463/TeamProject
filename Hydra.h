#pragma once
#include"Enemy.h"
class Hydra:public Enemy
{
public:
	Hydra();
	~Hydra();

	virtual void update();
	virtual HRESULT init();
};

