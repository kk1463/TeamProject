#include "stdafx.h"
#include "Player.h"
#include"gameNode.h"

Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init(PlayerName playername)
{
	_totalTile = SCENEMANAGER->getCurrentScene()->getTile();
	return S_OK;

}

void Player::release()
{
}

void Player::update()
{
	
}



void Player::KeyControl()
{

		//          1. 키 두개 사용했을떄 뚫는거   ,    2. 타일 주변 범위 검색해서 충돌 체크(렉줄이기)
	for (int i = 0; i < _totalTile.size(); i++)
	{
		if (getDistance(_totalTile[i]->getRect().left, _totalTile[i]->getRect().top,
			_playerInfo.rc.left, _playerInfo.rc.top) < 50)
		{

		}
			RECT temp;
			if (_totalTile[i]->getAttribute() == nonBlocking) continue;

			if (IntersectRect(&temp, &_playerInfo.rightColRc, &_totalTile[i]->getRect()))
			{
				if (_totalTile[i]->getRect().left < _playerInfo.rightColRc.right)
				{
					_playerInfo.rightMove = false;
				}
				break;


			}

			else if (_totalTile[i]->getRect().left >= _playerInfo.rightColRc.right && _playerInfo.rightMove == false)
			{
				_playerInfo.rightMove = true;
			}


			////
			if (IntersectRect(&temp, &_playerInfo.leftColRc, &_totalTile[i]->getRect()))
			{
				if (_totalTile[i]->getRect().right > _playerInfo.leftColRc.left)
				{
					_playerInfo.leftMove = false;
				}
				break;
			}

			else if (_totalTile[i]->getRect().right <= _playerInfo.leftColRc.left && _playerInfo.leftMove == false)
			{
				_playerInfo.leftMove = true;
			}
			////
			if (IntersectRect(&temp, &_playerInfo.botColRc, &_totalTile[i]->getRect()))
			{
				if (_totalTile[i]->getRect().top < _playerInfo.botColRc.bottom)
				{
					_playerInfo.downMove = false;
				}
				break;
			}

			else if (_totalTile[i]->getRect().top > _playerInfo.botColRc.bottom && _playerInfo.downMove == false)
			{
				_playerInfo.downMove = true;
			}
			////
			if (IntersectRect(&temp, &_playerInfo.topColRc, &_totalTile[i]->getRect()))
			{
				if (_totalTile[i]->getRect().bottom > _playerInfo.topColRc.top)
				{
					_playerInfo.upMove = false;
				}
				break;
			}

			else if (_totalTile[i]->getRect().bottom < _playerInfo.topColRc.top && _playerInfo.upMove == false)
			{
				_playerInfo.upMove = true;
			}
		
	}
}

void Player::PlayerStateChange()
{
}



