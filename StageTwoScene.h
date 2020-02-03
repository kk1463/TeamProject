#pragma once
#include"BasicScene.h"
class StageTwoScene :public BasicScene
{
private:

public:
	StageTwoScene();
	~StageTwoScene();

	virtual HRESULT init();
	virtual void render();
	virtual void update();
};

