#include "stdafx.h"
#include "EnemyManager.h"
#include"gameNode.h"
EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	return S_OK;
}

void EnemyManager::release()
{
	_vEm.clear();
}

void EnemyManager::setEnemy(GameObject* enemy)
{
	_vEm.push_back(enemy);
}

void EnemyManager::setTile(vector<tagTile*> ins)
{
	for (int i = 0; i < _vEm.size(); i++)
	{
		((Enemy*)_vEm[i])->setTile(ins);
	}
}

void EnemyManager::eraseEnemy(GameObject * ins)
{
	_viEm = _vEm.begin();
	for (; _viEm != _vEm.end();)
	{
		GameObject* temp = *_viEm;
		if (temp == ins)
		{
			_vEm.erase(_viEm);
			SCENEMANAGER->getCurrentScene()->deleteObject(ins);
			break;
		}
		else ++_viEm;

	}
}



