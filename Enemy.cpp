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
	return S_OK;
}


void Enemy::release() // 에너미가 죽었다
{
}



void Enemy::update() // 에너미가 움직인다.
{
}

void Enemy::setTile(vector<tagTile*> ins) // 에너미가 타일을 남기고 죽다.
{
	_tiles = ins;
}


