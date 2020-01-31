#include "stdafx.h"
#include "StageOneScene.h"


StageOneScene::StageOneScene()
{
}


StageOneScene::~StageOneScene()
{
}

void StageOneScene::update()
{
	BasicScene::update();
	UIMANAGER->update();
  	if (ENEMYMANAGER->getEnemy().size()==0)
	{
		SCENEMANAGER->changeScene("stageTwo");
	}
	
}

HRESULT StageOneScene::init()
{

	_tiles = TILEMANAGER->load("Stage/StageOne.txt");
	TILEMANAGER->loadObj("Object/stageOne.txt", "stageOne");
	return S_OK;
}

void StageOneScene::render()
{ 
	BasicScene::render();

	//RECT rc = PLAYERMANGER->get_vPlayer()[0]->getColRect();

	//Rectangle(getMemDC(), rc);

	UIMANAGER->render();

}
