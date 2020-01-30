#include "stdafx.h"
#include "Enemy.h"
#include"gameNode.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
HRESULT Enemy::init()
{
	cout << "EnemyInit" << endl;
	_tiles = SCENEMANAGER->getCurrentScene()->getTile();
	return S_OK;
}


void Enemy::release()
{
}



void Enemy::update()
{
}

void Enemy::setTile(vector<tagTile*> ins)
{
	_tiles = ins;
}


