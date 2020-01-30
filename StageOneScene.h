#pragma once
#include"BasicScene.h"


class StageOneScene:public BasicScene
{
private:
	
public:
	StageOneScene();
	~StageOneScene();
	virtual void Start();
	virtual HRESULT init();
	virtual void render();

	virtual void release();
};

