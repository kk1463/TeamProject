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
	cout << "EnemyInit" << endl; // ���ʹ̴� ������
	_tiles = SCENEMANAGER->getCurrentScene()->getTile();

	


	en.leftMove = true;
	en.upMove = true;
	en.downMove = true;
	en.rightMove = true;


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

	


}

void Enemy::setTile(vector<tagTile*> ins) // ���ʹ̰� Ÿ���� ����� �״�.
{
	_tiles = ins;
}


