#include "stdafx.h"
#include "Flower.h"
#include"gameNode.h"

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
	IMAGEMANAGER->addFrameImage("F_idle", "img/flower/idle.bmp", 328, 128, 2, 1, true, RGB(255, 0, 255));
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
	int Flower_Idle[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("F_idle", "F_idle", Flower_Idle, 2, FPS, true);
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

	en.img = IMAGEMANAGER->findImage("F_idle");
	en.Ani = KEYANIMANAGER->findAnimation("F_idle");
	en.changeAni = true;
	en.Ani->start();

	_up = true;
	left = false;
	right = false;
	atk = false;
	atkL = false;
	atkR = false;
	idle1 = true;

	en.x = _center.x;
	en.y = _center.y;

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
	//cout <<"x:"<< en.x << ",y:" <<en.y << endl;
	//cout << "x:" << _center.x << ",y:" << _center.y << endl;
	//POINT centerPos = getCenterPos(en.colRc);
	
	en.colRc = RectMakeCenter(en.x+90, en.y+70, 150, 150);
	en.rightColRc = RectMakeCenter(en.colRc.right + 10, en.colRc.top + 80, 10, 100);
	en.leftColRc = RectMakeCenter(en.colRc.left - 10, en.colRc.top + 80, 10, 100);
	en.topColRc = RectMakeCenter(en.colRc.left + 20, en.colRc.top - 2, 30, 3);
	en.botColRc = RectMakeCenter(en.colRc.left + 20, en.colRc.bottom + 2, 30, 3);

	this->setCheckRect_Right(en.rightColRc);
	this->setCheckRect_Left(en.leftColRc);
	this->setCheckRect_Top(en.topColRc);
	this->setCheckRect_Bottom(en.botColRc);



	switch (en._enState)
	{
	case move1:
		moving();
		break;
	case atk1:
		attack();
		break;
	case hit1:
		hit();
		break;
	case dead1:
		die();
		break;
	default:
		break;
	}

	if (en.changeAni)
	{
		F_state();
	}

	

	

}

void Flower::moving()
{
	


	count++;
    RECT rc = PLAYERMANGER->get_vPlayer()[0]->getColRect();
	RECT temp;
	// ■■■■■■■■■■■처음 등장 상태■■■■■■■■■■■■
	if (_up)
	{
		POINT ins = getCenterPos(PLAYERMANGER->get_vPlayer()[0]->getColRect());
		//cout << rc.left << endl;
		//cout << ins.x << "," << ins.y << endl;
		
		if (IntersectRect(&temp, &en.colRc, &rc))
		{
			en.changeAni = true;
			en.state = Up;
			en.dir = LEFT;
		}
		if (en.state == Up && en.Ani->getFrameNumber() == 17)
		{
			cout << "충돌" << endl;
			_up = false;
			left = true;
			en.changeAni = true;
			
			

		}
	}



	// ■■■■■■■■■■■■방향전환 아이들■■■■■■■■■■■■
	
	
		if (left)
		{
			en.state = Idle;
			if (en.state == Idle && en.x > PLAYERMANGER->get_vPlayer()[0]->getColRect().right - 50)
			{
				en.dir = LEFT;
				en.changeAni = true;
				left = false;
				right = true;
				atkL = true;


			}
		}
	
		if (right)
		{
			en.state = Idle;
			if (en.state == Idle && en.x < PLAYERMANGER->get_vPlayer()[0]->getColRect().left - 150)
			{
				en.dir = RIGHT;
				en.changeAni = true;
				left = true;
				right = false;
				atkR = true;


			}

		}
	
}

void Flower::F_state()
{
	
	if(idle1)
	{
		en.state = Idle;
		en.dir = DOWN;
		en.changeAni = true;
		idle1 = false;
	}
	else
	{
		switch (en.state)
		{
		case Up: 
			switch (en.dir)
			{
			case LEFT:
				en.Ani = KEYANIMANAGER->findAnimation("F_UP_Left");
				en.img = IMAGEMANAGER->findImage("F_UP_Left");
				en.Ani->start();
				en.changeAni = false;
				break;

			case RIGHT:
				en.Ani = KEYANIMANAGER->findAnimation("F_UP_Right");
				en.img = IMAGEMANAGER->findImage("F_UP_Right");
				en.Ani->start();
				en.changeAni = false;
				break;
			}
			break;
		case Idle:
			switch (en.dir)
			{
			case LEFT:
				en.Ani = KEYANIMANAGER->findAnimation("F_idle_Left");
				en.img = IMAGEMANAGER->findImage("F_idle_Left");
				en.Ani->start();
				en.changeAni = false;
				break;
			case RIGHT:
				en.Ani = KEYANIMANAGER->findAnimation("F_idle_Right");
				en.img = IMAGEMANAGER->findImage("F_idle_Right");
				en.Ani->start();
				en.changeAni = false;
				break;
			case DOWN:
				en.Ani = KEYANIMANAGER->findAnimation("F_idle");
				en.img = IMAGEMANAGER->findImage("F_idle");
				en.Ani->start();
				en.changeAni = false;
			}
			break;
		case Atk:
			switch (en.dir)
			{
			case LEFT:

				en.Ani = KEYANIMANAGER->findAnimation("F_Atk_Left");
				en.img = IMAGEMANAGER->findImage("F_Atk_Left");
				en.Ani->start();
				en.changeAni = false;
				break;
			case RIGHT:
				en.Ani = KEYANIMANAGER->findAnimation("F_Atk_Right");
				en.img = IMAGEMANAGER->findImage("F_Atk_Right");
				en.Ani->start();
				en.changeAni = false;
				break;
			}
			break;
		 

		}
	}
	if (en.Ani->getMaxFrameNumber() == en.Ani->getFrameNumber())
		
	{
		en.changeAni = true;
		count = 0;
	}
}

void Flower::attack()
{
	RECT rc = PLAYERMANGER->get_vPlayer()[0]->getColRect();
	RECT temp;
	if (IntersectRect(&temp, &en.leftColRc, &rc))
	{

		cout << "들어옴????" << endl;
		en.state = Atk;
		en.dir = LEFT;
		en.changeAni = true;


	}
	if (IntersectRect(&temp, &en.rightColRc, &rc))
	{
		en.state = Atk;
		en.dir = RIGHT;
		en.changeAni = true;

	}
	if (en.Ani->getMaxFrameNumber() == en.Ani->getFrameNumber()
		|| en.Ani->getFrameNumber() == 0)
	{
		en.changeAni = true;
		count = 0;
	}

}

void Flower::hit()
{
}

void Flower::die()
{
}



