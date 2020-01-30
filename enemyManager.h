#pragma once
#include <vector>
#include "GameObject.h"
#include"tagTile.h"


class EnemyManager : public singletonBase<EnemyManager>
{
private:
	typedef vector<GameObject*>				vEnemy;
	typedef vector<GameObject*>::iterator	viEnemy;

private:
	vEnemy _vEm;
	viEnemy _viEm;



public:
	EnemyManager();
	~EnemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	void setEnemy(GameObject* enemy); //에너미 세팅

	void setTile(vector<tagTile*> ins);



};



