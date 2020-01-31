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

	
	for (int i = 0;i < _vPlayer.size();i++)
	{
		RECT temp;		
		RECT rc = _vPlayer[0]->getColRect();
		int _playerDir = _vPlayer[0]->getPlayerDir();
		if ((IntersectRect(&temp, &en.colRc, &rc)))//&&(en.angry)))
		{
			en._enState = atk1;
			break;
		}
		
	cout << _playerDir << endl;
	}


	if (en.hp < 0)
	{
		ENEMYMANAGER->eraseEnemy(this);
	}
	
	if (en._enState != move1)
	{
		en.count++;
		if (en.count > 20)
		{
			en._enState = move1;
			en.count = 0;
		}
	}

	

}

void Enemy::hit()
{

}

void Enemy::attaked(int atk)
{
	en.count++;
	
	switch (en.Movecheck)
	{
	case 0:		
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
	
	en._enState = hit1;
	
	
	en.angry = true;
	en.hp -= atk;
	
	
}

void Enemy::setTile(vector<tagTile*> ins) // 에너미가 타일을 남기고 죽다.
{
	_tiles = ins;
}


