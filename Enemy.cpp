#include "stdafx.h"
#include "Enemy.h"
#include"gameNode.h"

Enemy::Enemy() //���ʹ��̴�.
{
}

Enemy::~Enemy() // ���ʹ̰� �������
{
}
HRESULT Enemy::init() // ���ʹ̰� �����Ѵ�.
{
	_tiles = SCENEMANAGER->getCurrentScene()->getTile();



	en.leftMove = true;
	en.upMove = true;
	en.downMove = true;
	en.rightMove = true;
	
	en.angry = false;
	getPlayerPos = getPlayerAngle = 0;


	return S_OK;
}


void Enemy::release() // ���ʹ̰� �׾���
{
}



void Enemy::update() // ���ʹ̰� �����δ�.
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
		if ((IntersectRect(&temp, &en.colRc, &rc)&&(en.angry)))
		{
			en._enState = atk1;

		}
		
	}

	











}

void Enemy::hit()
{

}

void Enemy::attaked()
{
	ENEMYMANAGER->eraseEnemy(this);
}

void Enemy::setTile(vector<tagTile*> ins) // ���ʹ̰� Ÿ���� ����� �״�.
{
	_tiles = ins;
}


