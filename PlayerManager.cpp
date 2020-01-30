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

void PlayerManager::update()
{
	collision();
}

void PlayerManager::release()
{
}

void PlayerManager::collision()
{
	RECT temp;
	for (int i = 0; i < SCENEMANAGER->getCurrentScene()->getGameObject().size(); i++)
	{
		if (IntersectRect(&temp, &SCENEMANAGER->getCurrentScene()->getGameObject()[i]->getColRect(), &SCENEMANAGER->getCurrentScene()->getGameObject()[i]->getCheckRect_Left()))
		{
			if (SCENEMANAGER->getCurrentScene()->getGameObject()[i]->getObject() == RABBIT)
			{
				cout << endl;
			}
		
			
		}
	}

	
		
	
}





