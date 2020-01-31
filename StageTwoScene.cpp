#include "stdafx.h"
#include "StageTwoScene.h"


StageTwoScene::StageTwoScene()
{
}


StageTwoScene::~StageTwoScene()
{
}

HRESULT StageTwoScene::init()
{
	
	_tiles = TILEMANAGER->load("Stage/StageTwo.txt");

	TILEMANAGER->loadObj("Object/stageOne.txt", "stageTwo");
	return S_OK;
}

void StageTwoScene::render()
{
	BasicScene::render();
}
