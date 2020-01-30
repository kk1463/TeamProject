#include "stdafx.h"
#include "Slime.h"


Slime::Slime()
{
}


Slime::~Slime()
{
}

HRESULT Slime::init()
{

	//idle
	IMAGEMANAGER->addFrameImage("S_idle", "img/slime/idle.bmp", 400, 36, 8, 1, true, RGB(255, 0, 255));
	//Atk						
	IMAGEMANAGER->addFrameImage("S_Atk_Down", "img/slime/Atk_Down.bmp", 756, 52, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Atk_Up", "img/slime/Atk_Up.bmp", 756, 52, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Atk_Left", "img/slime/Atk_Left.bmp", 1044, 32, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Atk_Right", "img/slime/Atk_Right.bmp", 1044, 32, 18, 1, true, RGB(255, 0, 255));
	//run						
	IMAGEMANAGER->addFrameImage("S_Run", "img/slime/Run_2.bmp", 700, 46, 14, 1, true, RGB(255, 0, 255));
	//dmg					
	IMAGEMANAGER->addFrameImage("S_Dmg", "img/slime/Dmg_Up.bmp", 108, 28, 2, 1, true, RGB(255, 0, 255));
	//dead
	IMAGEMANAGER->addFrameImage("S_dead", "img/slime/S_dead.bmp", 954, 58, 9, 1, true, RGB(255, 0, 255));


	//idle
	int Slime_Idle[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("S_idle", "S_idle", Slime_Idle, 8, FPS, true);
	//Atk
	int Slime_Atk_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Left", "S_Atk_Left", Slime_Atk_Left, 18, FPS, true);
	int Slime_Atk_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Right", "S_Atk_Right", Slime_Atk_Right, 18, FPS, true);
	int Slime_Atk_Down[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Down", "S_Atk_Down", Slime_Atk_Down, 18, FPS, true);
	int Slime_Atk_Up[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Atk_Up", "S_Atk_Up", Slime_Atk_Up, 18, FPS, true);
	//run
	int Slime_Run[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Run", "S_Run", Slime_Run, 14, FPS, true);
	//dmg					
	int Slime_Dmg[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("S_Dmg", "S_Dmg", Slime_Dmg, 2, FPS, true);
	//Dead
	int Slime_Dead[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("S_dead", "S_dead", Slime_Dead, 9, FPS, true);






	en.name = Name_Slime;



	en.img = IMAGEMANAGER->findImage("S_idle");
	en.Ani = KEYANIMANAGER->findAnimation("S_idle");
	en.changeAni = true;
	en.Ani->start();

	en.x = WINSIZEX / 2+200;
	en.y = WINSIZEY / 2-200;

	this->setimage(en.img);
	this->setAni(en.Ani);

	Enemy::init();

	return S_OK;
}

void Slime::release()
{
}

void Slime::update()
{
	en.colRc = RectMakeCenter(en.x + 24, en.y + 25, 40, 40);
	en.rightColRc = RectMakeCenter(en.colRc.right + 2, en.colRc.top + 20, 3, 30);
	en.leftColRc = RectMakeCenter(en.colRc.left - 2, en.colRc.top + 20, 3, 30);
	en.topColRc = RectMakeCenter(en.colRc.left + 20, en.colRc.top - 2, 30, 3);
	en.botColRc = RectMakeCenter(en.colRc.left + 20, en.colRc.bottom + 2, 30, 3);

	this->setCheckRect_Right(en.rightColRc);
	this->setCheckRect_Left(en.leftColRc);
	this->setCheckRect_Top(en.topColRc);
	this->setCheckRect_Bottom(en.botColRc);

	Enemy::update();


}

