#pragma once
#include"BasicScene.h"


class StageOneScene :public BasicScene
{
private:

	image* _start;
	image* _clear;

	int _alpha;
	bool _startStop;
	int Stageonecnt;


	bool _Allclear;

public:
	StageOneScene();
	~StageOneScene();

	virtual void Start();
	virtual void update();
	virtual HRESULT init();
	virtual void render();
};

