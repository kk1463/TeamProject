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
	_vPlayer.clear();
}

void PlayerManager::collision()
{

	RECT temp;
	vector<GameObject*>& objs = SCENEMANAGER->getCurrentScene()->getGameObject();
	vector<GameObject*>::iterator Iter = objs.begin();
	for (; Iter != objs.end();)
	{
		GameObject* temp = *Iter;
		if (PtInRect(&temp->getColRect(), _ptMouse) && temp->getObject() != PLAYER)
		{
			SCENEMANAGER->getCurrentScene()->deleteObject(temp);
			break;
		}
		else ++Iter;
	}

}





