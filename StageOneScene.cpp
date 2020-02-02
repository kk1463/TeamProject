#include "stdafx.h"
#include "StageOneScene.h"


StageOneScene::StageOneScene()
{
}


StageOneScene::~StageOneScene()
{
}

void StageOneScene::Start()
{
}

void StageOneScene::update()
{
	BasicScene::update();
	UIMANAGER->update();

	
	cout << _start->getX()<<","<< Stageonecnt<<","<< WINSIZEX / 2 - 400 << endl;
	
}

HRESULT StageOneScene::init()
{

	_tiles = TILEMANAGER->load("Stage/StageOne.txt");
	TILEMANAGER->loadObj("Object/stageOne.txt", "stageOne");
	PLAYERMANGER->init();

	_start = IMAGEMANAGER->addImage("fight", "fightStage1.bmp", 800, 226, true, RGB(255, 0, 255));
	_clear = IMAGEMANAGER->addImage("clear", "allclear.bmp", 800, 461, true, RGB(255, 0, 255));

	_start = new image;
	_start = IMAGEMANAGER->findImage("fight");
	_start->setX(-900);
	_start->setY(WINSIZEY / 2 - 300);

	_clear = new image;
	_clear = IMAGEMANAGER->findImage("clear");
	_clear->setX(150);
	_clear->setY(-900);




	_startStop = false;
	_Allclear = false;

	Stageonecnt = 0;

	return S_OK;
}

void StageOneScene::render()
{ 
	BasicScene::render();

	
	UIMANAGER->render();

}
