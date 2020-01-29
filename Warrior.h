#pragma once
#include "Player.h" 

class Warrior : public Player
{
private:

public:
	Warrior();
	~Warrior();


	virtual HRESULT init(PlayerName playername);
	virtual void release();
	virtual void update();
	virtual void KeyControl();
	virtual void PlayerStateChange();
};


