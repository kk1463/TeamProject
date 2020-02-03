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

	_start = IMAGEMANAGER->addImage("fight2", "fightStage2.bmp", 800, 226, true, RGB(255, 0, 255));
	_clear = IMAGEMANAGER->addImage("clear", "allclear2.bmp", 800, 461, true, RGB(255, 0, 255));

	_start->setX(-900);
	_start->setY(WINSIZEY / 2 - 300);

	_clear = IMAGEMANAGER->findImage("clear");
	_clear->setX(150);
	_clear->setY(-900);


	_startStop = false;
	_Allclear = false;

	TILEMANAGER->loadObj("Object/stageOne.txt", "stageTwo");
	PLAYERMANGER->init();
	return S_OK;
}

void StageTwoScene::render()
{
	BasicScene::render();

	

	UIMANAGER->render();
}

void StageTwoScene::update()
{
	BasicScene::update();
	UIMANAGER->update();



}
