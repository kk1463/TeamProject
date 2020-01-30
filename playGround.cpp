#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}


HRESULT playGround::init()
{
	gameNode::init(true);
	IMAGEMANAGER->addFrameImage("mapTiles", "img/Stage/����_�������1��.bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Second_floor", "img/Stage/2����_�������_2.bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ladder", "img/Stage/��ٸ�.bmp", 0, 0, 364, 184, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ladder_two", "img/Stage/��ٸ�2.bmp", 0, 0, 371, 234, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Second_Map", "img/Stage/Second_Map.bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Boss_Map_Fall", "img/Stage/Boss_Map(F).bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Boss_Map_Summer", "img/Stage/Boss_Map(S).bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Boss_Map_Winter", "img/Stage/Boss_Map(W).bmp", 0, 0, 800, 640, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("BackGround", "img/Stage/BackGround.bmp", WINSIZEX, WINSIZEY,false,RGB(0,0,0));


	IMAGEMANAGER->addImage("Hydra", "img/Hydra.bmp", 303, 487, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Player", "img/Player.bmp", 60, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Slime", "img/Slime.bmp", 50, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Rabbit", "img/Rabbit.bmp", 50, 44, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Flower", "img/Flower.bmp", 146, 126, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fall_tree", "img/MapObject/��������.bmp", 158, 180, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("normal_stone", "img/MapObject/�⺻_��.bmp", 47, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("root", "img/MapObject/�����Ѹ�.bmp", 35, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tree", "img/MapObject/���ڶ�����.bmp", 130, 188, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("winter_tree", "img/MapObject/���ڶ������������¹���.bmp", 158, 187, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("marble", "img/MapObject/�����ʱ���_ȸ��.bmp", 50, 54, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bush", "img/MapObject/�ν�.bmp", 100, 98, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("rock", "img/MapObject/��ֹ���2.bmp", 36, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("big_stone", "img/MapObject/ū_��.bmp", 59, 59, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stone", "img/MapObject/��.bmp", 46, 30, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ladder_right", "img/MapObject/��ٸ�_������.bmp", 371, 234, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ladder_left", "img/MapObject/��ٸ�_����.bmp", 364, 184, true, RGB(255, 0, 255));
	
	

	SCENEMANAGER->addScene("stageOne", new StageOneScene);
	SCENEMANAGER->addScene("Loading", new LoadingScene);
	SCENEMANAGER->addScene("stageTwo", new StageTwoScene);

	SCENEMANAGER->changeScene("stageTwo");

	_pm = new PlayerManager;
	_pm->setEnemyManager(_em);
	_pm->init();
	

	_em = new EnemyManager;
	_em->setPlayerManager(_pm);
	_em->init();

	return S_OK;
	


}

// �̰��� ������ �Լ��̴�.
void playGround::release()
{
	gameNode::release();	// �̰��� ������ �Լ��̴�. feat. ����


}

// �̰��� ������Ʈ �Լ��̴�.
void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	KEYANIMANAGER->update();
	_pm->update();
}



// �̰��� ���� �Լ��̴�.
void playGround::render()
{

	PatBlt(getMemDC(), 0, 0, 3, WINSIZEY, WHITENESS);
//========================================================
	SCENEMANAGER->render();

	RECT rc=_pm->get_vPlayer()[0]->getColRc();
	Rectangle(getMemDC(), rc);

	if (KEYMANAGER->isToggleKey('2'))
	{
		RECT rc = _pm->get_vPlayer()[0]->getColRc();
		Rectangle(getMemDC(), rc);

		vector<GameObject*> ins = ENEMYMANAGER->getEnemy();
		for (int i = 0;i < ins.size();i++)
		{
			RECT _rc = ins[i]->getColRect();
			Rectangle(getMemDC(), _rc);
			RECT _rc1 = ins[i]->getCheckRect_Bottom();
			Rectangle(getMemDC(), _rc1);
			RECT _rc2 = ins[i]->getCheckRect_Top();
			Rectangle(getMemDC(), _rc2);
			RECT _rc3 = ins[i]->getCheckRect_Right();
			Rectangle(getMemDC(), _rc3);
			RECT _rc4 = ins[i]->getCheckRect_Left();
			Rectangle(getMemDC(), _rc4);			
		}
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		SCENEMANAGER->getCurrentScene()->eraseGameObj(0);
	}
	//Rectangle(getMemDC(), rc);
	//cout << i << endl;
	


//====================================================
	_backBuffer->render(getHDC(), 0, 0);
}

