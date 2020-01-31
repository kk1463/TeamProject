#pragma once
#include "gameNode.h"
#include"LoadingScene.h"
#include"StageOneScene.h"
#include"StageTwoScene.h"



#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define SPEED 7


class playGround : public gameNode
{

private:
	uiManager* _um;
	bool start = false;
	float HHPP;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	playGround();
	~playGround();
};

