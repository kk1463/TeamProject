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
	IMAGEMANAGER->addImage("Hydra", "img/Hydra.bmp", 303, 487, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Player", "img/Player.bmp", 60, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Slime", "img/Slime.bmp", 50, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Rabbit", "img/Rabbit.bmp", 50, 44, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Flower", "img/Flower.bmp", 146, 126, true, RGB(255, 0, 255));
	_tiles = TILEMANAGER->load("Stage/StageOne.txt");

	TILEMANAGER->loadObj("Object/stageOne.txt", "stageTwo");
	return S_OK;
}

void StageTwoScene::render()
{
	BasicScene::render();
}
