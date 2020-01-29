#pragma once
#include "Player.h"
#include "Warrior.h"`	

#include <vector>
class gameNode;


class PlayerManager 
{
private:

	vector<Player*> _vPlayer;

	Player* _player;

public:

	PlayerManager();
	~PlayerManager();

	HRESULT init();
	
	void release();
	vector<Player*> get_vPlayer() { return _vPlayer; }
};

