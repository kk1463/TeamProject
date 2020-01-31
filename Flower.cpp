#include "stdafx.h"
#include "Flower.h"


Flower::Flower()
{
}


Flower::~Flower()
{
}

HRESULT Flower::init()
{

	//idle
	IMAGEMANAGER->addFrameImage("F_idle_Right", "img/flower/idle_Right.bmp", 1660, 126, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_idle_Left", "img/flower/idle_Left.bmp", 1660, 126, 10, 1, true, RGB(255, 0, 255));
	//Atk						
	IMAGEMANAGER->addFrameImage("F_Atk_Left", "img/flower/Atk_Left.bmp", 3304, 176, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_Atk_Right", "img/flower/Atk_Right.bmp", 3304, 176, 14, 1, true, RGB(255, 0, 255));
	//up						
	IMAGEMANAGER->addFrameImage("F_UP_Left", "img/flower/UP_Left.bmp", 2952, 128, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_UP_Right", "img/flower/UP_Right.bmp", 2952, 128, 18, 1, true, RGB(255, 0, 255));
	//dmg					
	IMAGEMANAGER->addFrameImage("F_Dmg_Left", "img/flower/Dmg_Left.bmp", 608, 106, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("F_Dmg_Right", "img/flower/Dmg_Right.bmp", 608, 106, 4, 1, true, RGB(255, 0, 255));
	//deadEffect
	IMAGEMANAGER->addFrameImage("F_deadEffect", "img/flower/F_deadEffect.bmp", 2728, 98, 22, 1, true, RGB(255, 0, 255));


	//idle
	int Flower_Idle_Right[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("F_idle_Right", "F_idle_Right", Flower_Idle_Right, 10, FPS, true);
	int Flower_Idle_Left[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("F_idle_Left", "F_idle_Left", Flower_Idle_Left, 10, FPS, true);
	//Atk
	int Flower_Atk_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Atk_Left", "F_Atk_Left", Flower_Atk_Left, 14, FPS, true);
	int Flower_Atk_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Atk_Right", "F_Atk_Right", Flower_Atk_Right, 14, FPS, true);
	//up
	int Flower_Up_Left[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("F_UP_Left", "F_UP_Left", Flower_Up_Left, 18, FPS, true);
	int Flower_Up_Right[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("F_UP_Right", "F_UP_Right", Flower_Up_Right, 18, FPS, true);
	//Dmg
	int Flower_Dmg_Left[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Dmg_Left", "F_Dmg_Left", Flower_Dmg_Left, 4, FPS, true);
	int Flower_Dmg_Right[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("F_Dmg_Right", "F_Dmg_Right", Flower_Dmg_Right, 4, FPS, true);
	//deadEffect
	int Flower_DeadEffect[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
	KEYANIMANAGER->addArrayFrameAnimation("F_deadEffect", "F_deadEffect", Flower_DeadEffect, 22, FPS, true);




	en.name = Name_Flower;
	en.hp = 10;

	en.img = IMAGEMANAGER->findImage("F_idle_Right");
	en.Ani = KEYANIMANAGER->findAnimation("F_idle_Right");
	en.changeAni = true;
	en.Ani->start();

	this->setimage(en.img);
	this->setAni(en.Ani);

	Enemy::init();
	return S_OK;
}

void Flower::release()
{
}

void Flower::update()
{
	Enemy::update();

	en.colRc = RectMakeCenter(en.x + 80, en.y + 70, 60, 60);
	en.rightColRc = RectMakeCenter(en.colRc.right + 2, en.colRc.top + 30, 3, 50);
	en.leftColRc = RectMakeCenter(en.colRc.left - 2, en.colRc.top + 30, 3, 50);
	en.topColRc = RectMakeCenter(en.colRc.left + 30, en.colRc.top - 2, 50, 3);
	en.botColRc = RectMakeCenter(en.colRc.left + 30, en.colRc.bottom + 2, 50, 3);

	this->setCheckRect_Right(en.rightColRc);
	this->setCheckRect_Left(en.leftColRc);
	this->setCheckRect_Top(en.topColRc);
	this->setCheckRect_Bottom(en.botColRc);





}



