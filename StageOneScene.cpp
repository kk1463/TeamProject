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
	TILEMANAGER->loadObj("Object/stageOne.txt", "stageOne");
	return S_OK;
}

void StageOneScene::render()
{
	BasicScene::render();
}
