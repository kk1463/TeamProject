#include "stdafx.h"
#include "Enemy.h"
#include"gameNode.h"

Enemy::Enemy() //에너미이다.
{
}

Enemy::~Enemy() // 에너미가 사라진다
{
}
HRESULT Enemy::init() // 에너미가 등장한다.
{
	_tiles = SCENEMANAGER->getCurrentScene()->getTile();
	


	en.leftMove = true;
	en.upMove = true;
	en.downMove = true;
	en.rightMove = true;
	
	en.angry = false;
	getPlayerPos = getPlayerAngle = en.count=0;

	en.playerX = en.playerY = 0;

	en.x = getCenterPos(_rc).x;
	en.y = getCenterPos(_rc).y;
	return S_OK;
}


void Enemy::release() // 에너미가 죽었다
{
}



void Enemy::update() // 에너미가 움직인다.
{


	en.rc = RectMakeCenter(en.x, en.y, en.img->getFrameWidth(), en.img->getFrameHeight());
	en.senseRC = RectMakeCenter(en.x, en.y, en.img->getFrameWidth() * 2, en.img->getFrameHeight() * 2);
	

	this->setimage(en.img);
	this->setAni(en.Ani);
	this->setRect(en.rc);
	this->setRect(en.senseRC);
	this->setColRect(en.colRc);
	this->setCenter(PointMake(en.x, en.y));

	_vPlayer = PLAYERMANGER->get_vPlayer();



	for (int i = 0; i < _vPlayer.size(); i++)
	{
		RECT temp;
		RECT rc = _vPlayer[0]->getColRect();
		if ((IntersectRect(&temp, &en.colRc, &rc) && en.angry))
		{
			en._enState = atk1;
			break;
		}
	}

	if (en._enState == hit1)
	{
		en.count++;
		if (en.count > 30)
		{
			en._enState = move1;
			en.count = 0;
		}
	}
	if (en._enState == atk1)
	{
		en.count++;
		if (en.count > 80)
		{
			en._enState = move1;
			en.count = 0;
		}
	}
	if (_vPlayer.size() >= 1)
	{
		en.playerX = getCenterPos(_vPlayer[0]->getPlayerRect()).x;
		en.playerY = getCenterPos(_vPlayer[0]->getPlayerRect()).y;
		getPlayerPos = getDistance(en.x, en.y, _vPlayer[0]->getCenter().x, _vPlayer[0]->getCenter().y);
		getPlayerAngle = getAngle(en.x, en.y, _vPlayer[0]->getCenter().x, _vPlayer[0]->getCenter().y);
		en.PlayerAngle = getAngle(en.x, en.y, _vPlayer[0]->getCenter().x, _vPlayer[0]->getCenter().y);
		
	}
	else
	{
		en.angry = false;
	}
	//에너미 삭제문은 update 제일 마지막에 놔둘것
	if (en.hp < 0)
	{
		if (en.name == Name_Rabbit)
		{
			if (en.Movecheck == 1 || en.Movecheck == 3)
			{

				EFFECTMANAGER->play("R_dead_Right", en.x+20, en.y);
			}
			else
			{
				EFFECTMANAGER->play("R_dead_Left", en.x+20, en.y+10);
			}
		}
		if (en.name == Name_Slime)
		{			
			EFFECTMANAGER->play("S_dead", en.x + 20, en.y + 10);
		}



		ENEMYMANAGER->eraseEnemy(this);
		
	}
}

void Enemy::hit()
{

}

void Enemy::attaked(int atk)
{
	en.PlayerDirNumber = _vPlayer[0]->getPlayerDir();
	int x = getCenterPos(_vPlayer[0]->getPlayerRect()).x;
	int y = getCenterPos(_vPlayer[0]->getPlayerRect()).y;

	if (en.name == Name_Rabbit || en.name == Name_Slime)
	{
		switch (en.PlayerDirNumber)//맞았을때 player방향마주보게
		{
		case 0:	//오른쪽
			en.Movecheck = 0;
			if (en.x < x)
			{
				en.x -= 20;
			}
			if (en.x > x)
			{
				en.x += 20;
			}
			break;
		case 1://왼쪽
			en.Movecheck = 1;
			if (en.x < x)
			{
				en.x -= 20;
			}
			if (en.x > x)
			{
				en.x += 20;
			}
			break;
		case 2://탑
			en.Movecheck = 3;
			if (en.y > y)
			{
				en.y += 20;
			}
			if (en.y < y)
			{
				en.y -= 20;
			}
			break;
		case 3://바텀
			en.Movecheck = 2;
			if (en.y > y)
			{
				en.y += 20;
			}
			if (en.y < y)
			{
				en.y -= 20;
			}
			break;
		}
	}
	en._enState = hit1;	
	
	en.angry = true;
	en.hp -= atk;	
}

void Enemy::setTile(vector<tagTile*> ins) // 에너미가 타일을 남기고 죽다.
{
	_tiles = ins;
}


