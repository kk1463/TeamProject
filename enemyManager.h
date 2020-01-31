#pragma once
#include <vector>
#include "GameObject.h"
#include"tagTile.h"

class PlayerManager;

class EnemyManager : public singletonBase<EnemyManager>
{
private:
	typedef vector<GameObject*>				vEnemy;
	typedef vector<GameObject*>::iterator	viEnemy;

private:
	vEnemy _vEm;
	viEnemy _viEm;
	PlayerManager* _pm;



public:
	EnemyManager();
	~EnemyManager();

	virtual HRESULT init();
	virtual void release();


	vector<GameObject*> getEnemy() { return _vEm; }

	void setEnemy(GameObject* enemy); //에너미 세팅

	void setTile(vector<tagTile*> ins);

	void eraseEnemy(int num) { _vEm.erase(_vEm.begin() + num); }

	void setPlayerManager(PlayerManager* pm) { _pm = pm; }
	void eraseEnemy(GameObject* ins);
};



