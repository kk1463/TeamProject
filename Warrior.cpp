#include "stdafx.h"
#include "Warrior.h"


Warrior::Warrior()
{
}


Warrior::~Warrior()
{
}

HRESULT Warrior::init(PlayerName playername)
{
	IMAGEMANAGER->addFrameImage("idle", "img/warrior/idle/idle3.bmp", 810, 144, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("idleUp", "img/warrior/idle/idleUp.bmp", 990, 72, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("idleDown", "img/warrior/idle/idleDown2.bmp", 810, 72, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "img/warrior/move/move1.bmp", 900, 144, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("moveDown", "img/warrior/move/moveDown3.bmp", 810, 72, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("moveUp", "img/warrior/move/moveUp2.bmp", 1100, 72, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("atk", "img/warrior/atk/atk.bmp", 1560, 200, 13, 2, true, RGB(255, 0, 255));
	/*int idleRight[] = {0,1,2,3,4,5,6,7,8};
	KEYANIMANAGER->addArrayFrameAnimation("idleRight", "idle", idleRight, 9, 20, true);
	int idleLeft[] = { 9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("idleLeft", "idle", idleLeft, 9, 20, true);
	int idleDown[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("idleDown", "idleDown", idleDown, 9, 20, true);
	int idleUp[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("idleUp", "idleUp", idleUp, 9, 20, true);
	int moveRight[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("moveRight", "move", moveRight, 10, 20, true);
	int moveLeft[] = { 10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("moveLeft", "move", moveLeft, 10, 20, true);
	int moveDown[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("moveDown", "moveDown", moveDown, 10, 20, true);
	int moveUp[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("moveUp", "moveUp", moveUp, 10, 20, true);
*/
	KEYANIMANAGER->addCoordinateFrameAnimation("idleRight", "idle", 0, 8, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("idleLeft", "idle", 9, 17, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("idleUp", "idleUp", 0, 8, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("idleDown", "idleDown", 0, 8, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("moveRight", "move", 0, 9, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("moveLeft", "move", 10, 19, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("moveUp", "moveUp", 0, 9, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("moveDown", "moveDown", 0, 9, FPS, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("atkRight", "atk", 0, 12, 20, false,false);
	KEYANIMANAGER->addCoordinateFrameAnimation("atkLeft", "atk", 25, 13, 20, false, false);

	_playerInfo.playerName = PN_WARRIOR;

	_playerInfo.position.x = 300;
	_playerInfo.position.y = 300;
	_playerInfo.speed = 4;

	this->setimage(IMAGEMANAGER->findImage("idleDown"));
	this->setCenter(PointMake(_playerInfo.position.x, _playerInfo.position.y));

	_playerInfo.ani = KEYANIMANAGER->findAnimation("idleDown");
	_playerInfo.ani->start();
	this->setAni(_playerInfo.ani);
	_playerInfo.changeAni = true;

	_playerInfo.changeDir = true;
	_playerInfo.dirCount = 0;
	_playerInfo.movecheck = true;
	_playerInfo.leftMove = true;
	_playerInfo.upMove = true;
	_playerInfo.downMove = true;
	_playerInfo.rightMove = true;
	_playerInfo.atkState = false;
	Player::init(playername);
	return S_OK;


}

void Warrior::release()
{
}

void Warrior::update()
{
	
	KeyControl();

	if (_playerInfo.changeAni)
	{
		PlayerStateChange();
		
	}

	_playerInfo.rc = RectMakeCenter(_playerInfo.position.x + _playerInfo.img->getFrameWidth() / 2, _playerInfo.position.y + _playerInfo.img->getFrameHeight() / 2,
		_playerInfo.img->getFrameWidth(), _playerInfo.img->getFrameHeight());
	this->setimage(_playerInfo.img);
	this->setAni(_playerInfo.ani);
	this->setRect(_playerInfo.rc);
	this->setCenter(PointMake(_playerInfo.position.x, _playerInfo.position.y));
	
	_playerInfo.colRc = RectMakeCenter(_playerInfo.position.x+40, _playerInfo.position.y+40, 40, 40);
	this->setColRect(_playerInfo.colRc);
	_playerInfo.rightColRc = RectMakeCenter(_playerInfo.colRc.right+2, _playerInfo.colRc.top + 20,3, 30);
	_playerInfo.leftColRc = RectMakeCenter(_playerInfo.colRc.left-2 , _playerInfo.colRc.top + 20, 3, 30);
	_playerInfo.topColRc = RectMakeCenter(_playerInfo.colRc.left +20, _playerInfo.colRc.top-2 , 30, 3);
	_playerInfo.botColRc = RectMakeCenter(_playerInfo.colRc.left + 20, _playerInfo.colRc.bottom+2, 30, 3);
}


void Warrior::KeyControl()
{
	

	if (_playerInfo.dirCount < 0)
	{
		_playerInfo.dirCount = 0;
	}
	if (_playerInfo.dirCount > 2)
	{
		_playerInfo.dirCount = 2;
	}
	//cout << "���� : " << _playerInfo.direction << endl << "���� : " << _playerInfo.state << endl;
	//cout << "DirCount : " << _playerInfo.dirCount << endl;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_RIGHT) || (KEYMANAGER->isStayKeyDown(VK_UP) && KEYMANAGER->isStayKeyDown(VK_DOWN)))
	{
		_playerInfo.movecheck = false;
		_playerInfo.state = P_IDLE;
	}
	else { _playerInfo.movecheck = true; }

	if (_playerInfo.dirCount == 2)
	{
		_playerInfo.speed = 3;
	}
	else
	{
		_playerInfo.speed = 4;
	}


	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{

		_playerInfo.dirCount--;
		if (_playerInfo.dirCount < 1)
		{
			_playerInfo.state = P_IDLE;
			_playerInfo.direction = P_LEFT;

		}
		_playerInfo.changeAni = true;


	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_playerInfo.dirCount--;
		if (_playerInfo.dirCount < 1)
		{
			_playerInfo.state = P_IDLE;
			_playerInfo.direction = P_RIGHT;

		}
		_playerInfo.changeAni = true;

	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_playerInfo.dirCount--;
		if (_playerInfo.dirCount < 1)
		{
			_playerInfo.state = P_IDLE;
			_playerInfo.direction = P_UP;

		}
		_playerInfo.changeAni = true;

	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_playerInfo.dirCount--;

		if (_playerInfo.dirCount < 1)
		{
			_playerInfo.state = P_IDLE;
			_playerInfo.direction = P_DOWN;

		}
		_playerInfo.changeAni = true;

	}

	if (_playerInfo.movecheck)
	{

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{

			_playerInfo.changeDir = true;
			_playerInfo.dirCount++;
			_playerInfo.changeAni = true;
		}


		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{

			_playerInfo.changeDir = true;
			_playerInfo.dirCount++;
			_playerInfo.changeAni = true;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_playerInfo.changeDir = true;
			_playerInfo.dirCount++;
			_playerInfo.changeAni = true;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_playerInfo.changeDir = true;
			_playerInfo.dirCount++;
			_playerInfo.changeAni = true;
		}


		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_playerInfo.direction = P_LEFT;
			_playerInfo.state = P_MOVE;
			_playerInfo.changeDir = false;

			if (_playerInfo.leftMove)
			{
				_playerInfo.position.x -= _playerInfo.speed;
			}
		}

		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_playerInfo.direction = P_RIGHT;
			_playerInfo.state = P_MOVE;
			_playerInfo.changeDir = false;

			if (_playerInfo.rightMove)
			{
				_playerInfo.position.x += _playerInfo.speed;
			}
		}


		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_playerInfo.direction = P_UP;
			_playerInfo.state = P_MOVE;
			_playerInfo.changeDir = false;

			if (_playerInfo.upMove)
			{
				_playerInfo.position.y -= _playerInfo.speed;
			}
		}


		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_playerInfo.direction = P_DOWN;
			_playerInfo.state = P_MOVE;
			_playerInfo.changeDir = false;
			if (_playerInfo.downMove)
			{
				_playerInfo.position.y += _playerInfo.speed;
			}
		}
	}
	if (!_playerInfo.atkState)
	{

		if (KEYMANAGER->isOnceKeyDown('A'))
		{

			_playerInfo.atkState = true;
			_playerInfo.changeAni = true;
		}
	
		if (_playerInfo.atkState)
		{
			_playerInfo.state = P_ATK;
		}
	}

	if (_playerInfo.atkState)
	{
		_playerInfo.atkCount++;
		_playerInfo.movecheck = false;
		if (_playerInfo.atkCount > 30)
		{
			_playerInfo.atkState = false;
			_playerInfo.movecheck = true;
			_playerInfo.atkCount = 0;
		}
	}
	cout << "����ī��Ʈ : " << _playerInfo.atkCount << endl;
	Player::KeyControl();
}

void Warrior::PlayerStateChange()
{
	switch (_playerInfo.state)
	{
	case P_IDLE:
		switch (_playerInfo.direction)
		{
		case P_LEFT:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("idleLeft");
			_playerInfo.img = IMAGEMANAGER->findImage("idle");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;

		case P_RIGHT:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("idleRight");
			_playerInfo.img = IMAGEMANAGER->findImage("idle");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;

		case P_DOWN:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("idleDown");
			_playerInfo.img = IMAGEMANAGER->findImage("idleDown");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;
		case P_UP:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("idleUp");
			_playerInfo.img = IMAGEMANAGER->findImage("idleUp");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;
		}
		break;

	case P_MOVE:
		switch (_playerInfo.direction)
		{
		case P_LEFT:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("moveLeft");
			_playerInfo.img = IMAGEMANAGER->findImage("move");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;

		case P_RIGHT:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("moveRight");
			_playerInfo.img = IMAGEMANAGER->findImage("move");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;

		case P_DOWN:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("moveDown");
			_playerInfo.img = IMAGEMANAGER->findImage("moveDown");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;
		case P_UP:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("moveUp");
			_playerInfo.img = IMAGEMANAGER->findImage("moveUp");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;
		}
		break;
	case P_ATK:
		switch (_playerInfo.direction)
		{
		case P_LEFT:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("atkLeft");
			_playerInfo.img = IMAGEMANAGER->findImage("atk");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;

		case P_RIGHT:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("atkRight");
			_playerInfo.img = IMAGEMANAGER->findImage("atk");
			_playerInfo.ani->start();
			
			_playerInfo.changeAni = false;
			break;

		/*case P_DOWN:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("moveDown");
			_playerInfo.img = IMAGEMANAGER->findImage("moveDown");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;
		case P_UP:
			_playerInfo.ani = KEYANIMANAGER->findAnimation("moveUp");
			_playerInfo.img = IMAGEMANAGER->findImage("moveUp");
			_playerInfo.ani->start();
			_playerInfo.changeAni = false;
			break;*/
	
		}
		break;
	}
	
	

}

