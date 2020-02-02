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

	if (ENEMYMANAGER->getEnemy().size() == 0)
	{
		_Allclear = true;

		if (_clear->getY() >= 200)
		{
			++Stageonecnt;
			_Allclear = false;
			if (Stageonecnt >= 200)
			{
				SCENEMANAGER->changeScene("stageTwo");
			}

		}

	}

	if (_Allclear)
	{
		_clear->setY(_clear->getY() + 9);
	}

	if (!_startStop)
	{
		_start->setX(_start->getX() + 9);
	}


	if (_start->getX() >= WINSIZEX / 2 - 400)
	{
		++ Stageonecnt;
		
		_startStop = true;
		setGameStart(true);
		if (Stageonecnt >= 100)
		{
			_startStop = false;
		}
	}
	
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

	return S_OK;
}

void StageOneScene::render()
{ 
	BasicScene::render();

	IMAGEMANAGER->findImage("fight")->render(getMemDC(), _start->getX(), _start->getY());
	IMAGEMANAGER->findImage("clear")->render(getMemDC(), _clear->getX(), _clear->getY());
	UIMANAGER->render();

}
