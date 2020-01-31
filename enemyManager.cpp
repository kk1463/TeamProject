#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	setEnemy(new Enemy);

	return S_OK;
}

void EnemyManager::release()
{
	_vEm.clear();
}

void EnemyManager::update()
{
	KEYANIMANAGER->update();



	for (int i = 0; i < _vEm.size(); i++)
	{
		_vEm[i]->update();
	}
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



