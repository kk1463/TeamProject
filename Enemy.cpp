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
		RECT rc = _vPlayer[0]->getPlayerRect(); //왜 3개로 늘어낫지
		
		if ((IntersectRect(&temp, &en.colRc, &rc) && en.angry))
		{
			en._enState = atk1;	
			break;
		}
	}


	if (en.hp < 0)
	{
		ENEMYMANAGER->eraseEnemy(this);
	}
	

	if(en._enState ==hit1)
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
		if (en.count > 100)
		{
			en._enState = move1;
			en.count = 0;
		}
	}

	


	/*_vPlayer = PLAYERMANGER->get_vPlayer();

	for (int i = 0;i < _vPlayer.size();i++)
	{
		
		RECT temp;
		RECT rc = _vPlayer[0]->getColRect();

		if (IntersectRect(&temp, &en.colRc, &rc))
		{
			en.hit = true;
			
		}
		else
			en.hit = false;

		_vPlayer[0]->getCenter();

		getPlayerPos = getDistance(en.x,en.y,_vPlayer[0]->getCenter().x, _vPlayer[0]->getCenter().y);
		getPlayerAngle = getAngle(en.x, en.y, _vPlayer[0]->getCenter().x, _vPlayer[0]->getCenter().y);

	}
	*/

}

void Enemy::hit()
{


}

void Enemy::attaked(int atk)
{
	int _playerDir = _vPlayer[0]->getPlayerDir();
	int x = getCenterPos(_vPlayer[0]->getPlayerRect()).x;
	int y = getCenterPos(_vPlayer[0]->getPlayerRect()).y;
	switch (_playerDir)//맞았을때 player방향마주보게
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


	
	

	en._enState = hit1;		



	en.angry = true;
	en.hp -= atk;

	
	
}

void Enemy::setTile(vector<tagTile*> ins) // 에너미가 타일을 남기고 죽다.
{
	_tiles = ins;
}


