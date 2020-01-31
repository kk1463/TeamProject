#pragma once
#include "Player.h"
#include "Warrior.h"`	

#include <vector>
class gameNode;

class PlayerManager :public singletonBase<PlayerManager>
{
private:

	vector<Player*> _vPlayer;
	EnemyManager* _em;


public:

	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void release();
	vector<Player*> get_vPlayer() { return _vPlayer; }
};

