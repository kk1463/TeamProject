#include "stdafx.h"
#include "StageOneScene.h"


StageOneScene::StageOneScene()
{
}


StageOneScene::~StageOneScene()
{
}

HRESULT StageOneScene::init()
{
	
	

	_tiles = TILEMANAGER->load("Stage/StageOne.txt");
	TILEMANAGER->loadObj("Object/stageOne.txt","stageOne");
	for (int i = 0; i < _gameObj.size(); i++)
	{
		_gameObj[i]->init();
	}
	return S_OK;
}

void StageOneScene::render()
{
	BasicScene::render();
}
