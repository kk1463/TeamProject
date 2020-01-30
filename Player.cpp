#include "stdafx.h"
#include "Player.h"
#include"gameNode.h"


Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init()
{
	return S_OK;
}

HRESULT Player::init(PlayerName playername)
{
	_totalTile = SCENEMANAGER->getCurrentScene()->getTile();
	_vEnemy = ENEMYMANAGER->getEnemy();
	return S_OK;

}

void Player::release()
{
}

void Player::update()
{
	if (_playerInfo.atkState)
	{
		for (int i = 0;i < _vEnemy.size();i++)
		{
			RECT rc = _vEnemy[i]->getColRect();
			RECT temp;
			if (IntersectRect(&temp,&rc,&_playerInfo.rightColRc))
			{
				cout << _vEnemy[i]->getObject() << endl;
			}
		}
	}
}



void Player::KeyControl()
{

		//          1. 키 두개 사용했을떄 뚫는거   ,    2. 타일 주변 범위 검색해서 충돌 체크(렉줄이기)
	for (int i = 0; i < _totalTile.size(); i++)
	{
			RECT temp;
			if (_playerInfo.direction == P_RIGHT) 
			{
				if (IntersectRect(&temp, &_playerInfo.rightColRc, &_totalTile[i]->getRect())
					&&_totalTile[i]->getAttribute()==blocking)
				{
					
					_playerInfo.rightMove = false;

					break;
				}

				else
				{
					_playerInfo.rightMove = true;
				}
			}
			if (_playerInfo.direction == P_LEFT)
			{
				////
				if (IntersectRect(&temp, &_playerInfo.leftColRc, &_totalTile[i]->getRect())
					&& _totalTile[i]->getAttribute() == blocking)
				{
					_playerInfo.leftMove = false;
					break;
				}
				else 
				{
					_playerInfo.leftMove = true;
				}
			}
			////
			if (_playerInfo.direction == P_DOWN)
			{
				if (IntersectRect(&temp, &_playerInfo.botColRc, &_totalTile[i]->getRect())
					&& _totalTile[i]->getAttribute() == blocking)
				{
					_playerInfo.downMove = false;
						
					break;
				}

				else 
				{

					_playerInfo.downMove = true;
				}
				////
			}
			if (_playerInfo.direction == P_UP)
			{
				if (IntersectRect(&temp, &_playerInfo.topColRc, &_totalTile[i]->getRect())
					&& _totalTile[i]->getAttribute() == blocking)
				{
					
						_playerInfo.upMove = false;
						
					break;
				}

				else
				{
					_playerInfo.upMove = true;
					
				}
			}
		
	}

}

void Player::PlayerStateChange()
{
}

void Player::PlayerRectChange()
{
}






