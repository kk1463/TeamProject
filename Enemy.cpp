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
	cout << "EnemyInit" << endl; // 에너미는 끝났다
	_tiles = SCENEMANAGER->getCurrentScene()->getTile();

	


	en.leftMove = true;
	en.upMove = true;
	en.downMove = true;
	en.rightMove = true;


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

	


}

void Enemy::setTile(vector<tagTile*> ins) // 에너미가 타일을 남기고 죽다.
{
	_tiles = ins;
}


