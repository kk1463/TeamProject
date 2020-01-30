#pragma once
#include"BasicScene.h"
class StageTwoScene :public BasicScene
{
public:
	StageTwoScene();
	~StageTwoScene();
	virtual void Start();
	virtual HRESULT init();
	virtual void render();
};

