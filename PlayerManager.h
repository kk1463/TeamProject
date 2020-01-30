#pragma once
#include "Player.h"
#include "Warrior.h"`	

#include <vector>
class gameNode;
class EnemyManager;

class PlayerManager 
{
private:

	vector<Player*> _vPlayer;
	EnemyManager* _em;


public:

	PlayerManager();
	~PlayerManager();

	HRESULT init();
	void update();
	void release();
	vector<Player*> get_vPlayer() { return _vPlayer; }
	void setEnemyManager(EnemyManager* em) { _em = em; }
	void collision();
};

