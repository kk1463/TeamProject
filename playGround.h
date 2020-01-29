#pragma once
#include "gameNode.h"
#include"LoadingScene.h"
#include"StageOneScene.h"
#include"StageTwoScene.h"

#include"PlayerManager.h"

#include "EnemyManager.h"


#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define SPEED 7


class playGround : public gameNode
{
private:

	PlayerManager* _pm;


	EnemyManager* _em;



public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	playGround();
	~playGround();
};

