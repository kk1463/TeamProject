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

	count = 0;
	move = true;
	atk = false;

	en.changeAni = true;
	en.Ani->start();

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

	//테스트 움직이기 용
	//if (KEYMANAGER->isStayKeyDown('A'))Movecheck = 0;
	//if (KEYMANAGER->isStayKeyDown('D'))Movecheck = 1;
	//if (KEYMANAGER->isStayKeyDown('S'))Movecheck = 3;
	//if (KEYMANAGER->isStayKeyDown('W'))Movecheck = 2;


	if (!atk)S_move();
	if (!atk)collision();


	if (en.changeAni)
	{
		S_state();
	}







}

void Slime::collision()
{

	for (int i = 0; i < _tiles.size(); i++)
	{
		RECT temp;
		if (en.dir == RIGHT)
		{
			if (IntersectRect(&temp, &en.rightColRc, &_tiles[i]->getRect())
				&& _tiles[i]->getAttribute() == blocking)
			{
				en.rightMove = false;
				break;
			}
			else
			{
				en.rightMove = true;
			}
		}
		if (en.dir == LEFT)
		{
			if (IntersectRect(&temp, &en.leftColRc, &_tiles[i]->getRect())
				&& _tiles[i]->getAttribute() == blocking)
			{
				en.leftMove = false;
				break;
			}
			else
			{
				en.leftMove = true;
			}
		}
		if (en.dir == DOWN)
		{
			if (IntersectRect(&temp, &en.botColRc, &_tiles[i]->getRect())
				&& _tiles[i]->getAttribute() == blocking)
			{
				en.downMove = false;

				break;
			}

			else
			{

				en.downMove = true;
			}
		}
		if (en.dir == UP)
		{
			if (IntersectRect(&temp, &en.topColRc, &_tiles[i]->getRect())
				&& _tiles[i]->getAttribute() == blocking)
			{

				en.upMove = false;
				break;
			}

			else
			{
				en.upMove = true;

			}
		}
	}
}

void Slime::S_move()
{
	en.state = Run;
	en.SPEED = 1.7F;

	count++;
	if (Movecheck == 0)
	{
		en.dir = LEFT;
	}
	if (Movecheck == 1)
	{
		en.dir = RIGHT;
	}
	if (Movecheck == 2)
	{
		en.dir = UP;
	}
	if (Movecheck == 3)
	{
		en.dir = DOWN;
	}
	if (count >= 80)
	{
		en.changeAni = true;
		Movecheck = RND->getFromIntTo(0, 4); //공격 테스트를 위해 잠시 잠굼
		count = 0;
	}



	switch (en.dir)
	{
	case LEFT:
		en.Ani = KEYANIMANAGER->findAnimation("S_Run");
		en.img = IMAGEMANAGER->findImage("S_Run");
		if (en.leftMove)
		{
			en.x -= en.SPEED;
		}
		break;
	case RIGHT:
		en.Ani = KEYANIMANAGER->findAnimation("S_Run");
		en.img = IMAGEMANAGER->findImage("S_Run");
		if (en.rightMove)
		{
			en.x += en.SPEED;
		}
		break;
	case DOWN:
		en.Ani = KEYANIMANAGER->findAnimation("S_Run");
		en.img = IMAGEMANAGER->findImage("S_Run");
		if (en.downMove)
		{
			en.y += en.SPEED;
		}
		break;
	case UP:
		en.Ani = KEYANIMANAGER->findAnimation("S_Run");
		en.img = IMAGEMANAGER->findImage("S_Run");
		if (en.upMove)
		{
			en.y -= en.SPEED;
		}
		break;
	}
}

void Slime::S_state()
{
	switch (en.dir)
	{
	case LEFT:
		break;
	case RIGHT:
		break;
	case DOWN:
		break;
	case UP:
		break;
	}

	switch (en.state)
	{
	case Idle:

		en.Ani = KEYANIMANAGER->findAnimation("S_idle");
		en.img = IMAGEMANAGER->findImage("S_idle");
		en.Ani->start();
		en.changeAni = false;
		break;

	case Run:

		en.Ani->start();
		en.changeAni = false;
		break;


	case Atk:
		switch (en.dir)
		{
		case LEFT:
			//en.img = IMAGEMANAGER->findImage("R_atk_left");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			//en.img = IMAGEMANAGER->findImage("R_atk_right");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			//en.img = IMAGEMANAGER->findImage("R_atk_down");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Down");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			//en.img = IMAGEMANAGER->findImage("R_atk_up");
			//en.Ani = KEYANIMANAGER->findAnimation("R_atk_Up");
			en.Ani->start();
			en.changeAni = false;
			break;
		}
		break;
	case Dmg:
		switch (en.dir)
		{
		case LEFT:
			en.img = IMAGEMANAGER->findImage("R_dmg_left");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			en.img = IMAGEMANAGER->findImage("R_dmg_right");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			en.img = IMAGEMANAGER->findImage("R_dmg_down");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Down");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			en.img = IMAGEMANAGER->findImage("R_dmg_up");
			en.Ani = KEYANIMANAGER->findAnimation("R_dmg_Up");
			en.Ani->start();
			en.changeAni = false;
			break;
		}
		break;
	case Dead:
		switch (en.dir)
		{
		case LEFT:
			en.img = IMAGEMANAGER->findImage("R_dead_Left");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case RIGHT:
			en.img = IMAGEMANAGER->findImage("R_dead_Right");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		case DOWN:
			en.img = IMAGEMANAGER->findImage("R_dead_Left");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Left");
			en.Ani->start();
			en.changeAni = false;
			break;
		case UP:
			en.img = IMAGEMANAGER->findImage("R_dead_Right");
			en.Ani = KEYANIMANAGER->findAnimation("R_dead_Right");
			en.Ani->start();
			en.changeAni = false;
			break;
		}

		break;
	case deadEffect:
		en.img = IMAGEMANAGER->findImage("R_deadEffect");
		en.Ani = KEYANIMANAGER->findAnimation("R_deadEffect");
		en.Ani->start();
		en.changeAni = false;
		break;
	default:
		break;
	}
}

