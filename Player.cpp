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

	EFFECTMANAGER->addEffect("PlayerDead", "img/warrior/dead/PlayerDead.bmp", 2160, 100, 120, 100, 1.0f, 0.2f, 50);

	_playerDie = false;

	return S_OK;

}

void Player::release()
{
}

void Player::update()
{
	if (_playerInfo.atkState)
	{
		for (int i = 0; i < _vEnemy.size(); i++)
		{
			RECT rc = _vEnemy[i]->getColRect();
			RECT temp;
			if (IntersectRect(&temp, &rc, &_playerInfo.AtkRc))
			{
				if (_playerInfo.atkCount == 10)
				{
					_vEnemy[i]->attaked(5);

				}
			}
		}
	}



	for (int i = 0; i < _totalTile.size(); i++)
	{
		if (PtInRect(&_totalTile[i]->getRect(), getCenterPos(_colRc)))
		{
			_tileIdx = i;
			break;
		}
	}


	//cout<<getCenterPos(getColRect()).x<<","<< getCenterPos(getColRect()).y <<endl;

	this->SetPlayerAtkRc(_playerInfo.AtkRc);

	if (_playerInfo.hp <= 0) 
	{
		EFFECTMANAGER->play("PlayerDead",PLAYERMANGER->get_vPlayer()[0]->getCenter().x+
			40, PLAYERMANGER->get_vPlayer()[0]->getCenter().y+20);
		PLAYERMANGER->erasePlayer(this);
	}

}



void Player::KeyControl()
{

	for (int j = 0; j < _vEnemy.size(); j++)
	{
		RECT rc = _vEnemy[j]->getColRect();
		RECT temp;

		if (_playerInfo.direction == P_RIGHT|| _playerInfo.direction == P_LEFT)
		{
			if (IntersectRect(&temp, &_playerInfo.miniColRc, &_vEnemy[j]->getColRect()))
			{
				
				if (getCenterPos(_playerInfo.miniColRc).y < getCenterPos(_vEnemy[j]->getColRect()).y)
				{
					_playerInfo.position.y -= 2;
				}
				else
				{
					_playerInfo.position.y += 2;
				}
				break;
			}
		}
		else if(_playerInfo.direction == P_UP || _playerInfo.direction == P_DOWN)
		{
			if (IntersectRect(&temp, &_playerInfo.miniColRc, &_vEnemy[j]->getColRect()))
			{
				if (getCenterPos(_playerInfo.miniColRc).x < getCenterPos(_vEnemy[j]->getColRect()).x)
				{
					_playerInfo.position.x -= 2;
				}
				else
				{
					_playerInfo.position.x += 2;
				}
				break;
			}
		}
	}
	


	for (int i = 0; i < _totalTile.size(); i++)
	{
		RECT temp;

		if (_playerInfo.direction == P_RIGHT)
		{
			if (IntersectRect(&temp, &_playerInfo.rightColRc, &_totalTile[i]->getRect())
				&& _totalTile[i]->getAttribute() == blocking)
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

void Player::attaked(int atk)
{
	_playerInfo.hp -= atk;

	_playerInfo.state = P_DMG;
	
}








