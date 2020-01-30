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
	cout << _vPlayer.size() << endl;
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
	cout << _vPlayer.size() << endl;
	vector<GameObject*>& objs = SCENEMANAGER->getCurrentScene()->getGameObject();
	vector<GameObject*>::iterator Iter = objs.begin();
	for (; Iter != objs.end();)
	{
		GameObject* temp = *Iter;
		
		if (PtInRect(&temp->getColRect(), _ptMouse)&&temp->getObject()!=PLAYER)		
		{
			cout << "�浹!" << endl;
			//SCENEMANAGER->getCurrentScene()->deleteObject(temp);
			break;
		}
		else ++Iter;
	}





	
		
	
}





