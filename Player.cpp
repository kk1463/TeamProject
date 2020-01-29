#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init(PlayerName playername)
{

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
	
	for (int i = 0; i < TILEMANAGER->getTotalTile().size(); i++)
	{
		RECT temp;
		if (TILEMANAGER->getTotalTile()[i]->getAttribute() == nonBlocking) continue;
		
			if (IntersectRect(&temp, &_playerInfo.rightColRc, &TILEMANAGER->getTotalTile()[i]->getRect()))
			{
				if (TILEMANAGER->getTotalTile()[i]->getRect().left < _playerInfo.rightColRc.right)
				{
					_playerInfo.rightMove = false;
				}
				break;
			}

			else if (TILEMANAGER->getTotalTile()[i]->getRect().left >= _playerInfo.rightColRc.right && _playerInfo.rightMove == false)
			{
				_playerInfo.rightMove = true;
			}
			////
			if (IntersectRect(&temp, &_playerInfo.leftColRc, &TILEMANAGER->getTotalTile()[i]->getRect()))
			{
				if (TILEMANAGER->getTotalTile()[i]->getRect().right > _playerInfo.leftColRc.left)
				{
					_playerInfo.leftMove = false;
				}
				break;
			}

			else if (TILEMANAGER->getTotalTile()[i]->getRect().right <= _playerInfo.leftColRc.left && _playerInfo.leftMove == false)
			{
				_playerInfo.leftMove = true;
			}
			////
			if (IntersectRect(&temp, &_playerInfo.botColRc, &TILEMANAGER->getTotalTile()[i]->getRect()))
			{
				if (TILEMANAGER->getTotalTile()[i]->getRect().top < _playerInfo.botColRc.bottom )
				{
					_playerInfo.downMove = false;
				}
				break;
			}

			else if (TILEMANAGER->getTotalTile()[i]->getRect().top > _playerInfo.botColRc.bottom && _playerInfo.downMove == false)
			{
				_playerInfo.downMove = true;
			}
			////
			if (IntersectRect(&temp, &_playerInfo.topColRc, &TILEMANAGER->getTotalTile()[i]->getRect()))
			{
				if (TILEMANAGER->getTotalTile()[i]->getRect().bottom > _playerInfo.topColRc.top)
				{
					_playerInfo.upMove = false;
				}
				break;
			}

			else if (TILEMANAGER->getTotalTile()[i]->getRect().bottom < _playerInfo.topColRc.top && _playerInfo.upMove == false)
			{
				_playerInfo.upMove = true;
			}
	}
}

void Player::PlayerStateChange()
{
}



