#include "stdafx.h"
#include "PlayerManager.h"
#include"gameNode.h"

PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

HRESULT PlayerManager::init()
{
	Player* _warrior = new Warrior;
	_warrior->setOBJECT(PLAYER);
	_warrior->init(PN_WARRIOR);
	_vPlayer.push_back(_warrior);
	SCENEMANAGER->getCurrentScene()->setGameObj(_warrior);
	return S_OK;
}


void PlayerManager::release()
{
	_viPlayer = _vPlayer.begin();
	while(_vPlayer.size()>0)
	{
		GameObject* ins = *_viPlayer;
		_vPlayer.erase(_viPlayer);
		SCENEMANAGER->getCurrentScene()->deleteObject(ins);
	}
	_vPlayer.clear();

}

void PlayerManager::erasePlayer(GameObject * ins)
{
	_viPlayer = _vPlayer.begin();
	for (; _viPlayer != _vPlayer.end();)
	{
		GameObject* temp = *_viPlayer;
		if (temp == ins)
		{
			_vPlayer.erase(_viPlayer);
			SCENEMANAGER->getCurrentScene()->deleteObject(ins);
			break;
		}
		else ++_viPlayer;

	}
}





