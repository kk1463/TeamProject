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

	_Start2 = IMAGEMANAGER->addImage("fight2", "fightStage2.bmp", 800, 226, true, RGB(255, 0, 255));
	_Stage2clear = IMAGEMANAGER->addImage("clear", "allclear2.bmp", 800, 461, true, RGB(255, 0, 255));

	_Start2 = new image;
	_Start2 = IMAGEMANAGER->findImage("fight2");
	_Start2->setX(-900);
	_Start2->setY(WINSIZEY / 2 - 300);

	_Stage2clear = new image;
	_Stage2clear = IMAGEMANAGER->findImage("clear");
	_Stage2clear->setX(150);
	_Stage2clear->setY(-900);



	_Stagebool = false;
	_Stage2bool = false;

	TILEMANAGER->loadObj("Object/stageOne.txt", "stageTwo");
	PLAYERMANGER->init();
	return S_OK;
}

void StageTwoScene::render()
{
	BasicScene::render();

	IMAGEMANAGER->findImage("fight2")->render(getMemDC(), _Start2->getX(), _Start2->getY());
	IMAGEMANAGER->findImage("clear")->render(getMemDC(), _Stage2clear->getX(), _Stage2clear->getY());

	UIMANAGER->render();
}

void StageTwoScene::update()
{
	UIMANAGER->update();

	if (ENEMYMANAGER->getEnemy().size() == 0)
	{
		_Stage2bool = true;
		if (_Stage2clear->getY() >= 200)
		{
			++cnt;
			_Stage2bool = false;
			if (cnt >= 200)
			{
				SCENEMANAGER->changeScene("Ending");
			}

		}

	}

	if (_Stage2bool)
	{
		_Stage2clear->setY(_Stage2clear->getY() + 9);
	}


	if (!_Stagebool)
	{
		_Start2->setX(_Start2->getX() + 9);
	}

	if (_Start2->getX() >= WINSIZEX / 2 - 400)
	{
		++cnt;
		_Stagebool = true;
	
		if (cnt >= 100)
		{
			_Stagebool = false;
			setGameStart(true);
			
		}
	}


}
