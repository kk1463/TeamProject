#pragma once
#include"BasicScene.h"


class StageOneScene :public BasicScene
{
private:

	

public:
	StageOneScene();
	~StageOneScene();

	virtual void Start();
	virtual void update();
	virtual HRESULT init();
	virtual void render();
};

