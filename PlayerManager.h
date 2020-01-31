#pragma once
#include "Player.h"
#include "Warrior.h"`	

#include <vector>
class gameNode;

class PlayerManager :public singletonBase<PlayerManager>
{
private:


	

	vector<GameObject*> _vPlayer;
	vector<GameObject*>::iterator _viPlayer;
	EnemyManager* _em;
	 

public:

	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void release();
	vector<GameObject*> get_vPlayer() { return _vPlayer; }
};

