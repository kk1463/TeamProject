#pragma once
#include"BasicScene.h"
#include "gameNode.h"

#define LOADINGMAX 0

class progressBar;


class LoadingScene :public BasicScene
{
private:
	progressBar* _loadingBar;
	image* _background;
	image* _lodingcall;
	image* _baegyeong;
	image* _lodingIcon;
	image* _lodingMonster;
	image* _loadingFire;

	image* _cloud1;
	image* _cloud2;
	image* _cloud3;

	image* _pressButton;

	bool _swith;

	int _pressStart;
	int _loadingStart;

	float _cloud1x, _cloud2x, _cloud3x;

	animation* _loadingAni;
	animation* _fire;
public:
	LoadingScene();
	~LoadingScene();

	int _currentCount;

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

static DWORD CALLBACK threadFunction(LPVOID lpParameter);

