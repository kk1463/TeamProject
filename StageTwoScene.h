#pragma once
#include"BasicScene.h"
class StageTwoScene :public BasicScene
{
private:

	image* _Start2;
	image* _Stage2clear;

	int cnt;
	bool _Stagebool;

	bool _Stage2bool;

public:
	StageTwoScene();
	~StageTwoScene();

	virtual HRESULT init();
	virtual void render();
	virtual void update();
};

