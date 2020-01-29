#pragma once
#include "GameObject.h"
class gameNode;
#define FPS 8

enum PlayerName
{
	PN_WARRIOR,
	PN_WIZARD
};

enum Playerstate
{
	P_IDLE,
	P_MOVE,
	P_ATK,
	P_DMG,
	P_DEAD

};

enum Direction
{
	P_RIGHT,
	P_LEFT,
	P_UP,
	P_DOWN
};


struct PlayerInfo
{
	image* img;
	PlayerName playerName;
	RECT rc;
	POINT position;
	float speed;
	animation* ani;
	bool changeAni;
	Playerstate state;
	Direction direction;
	bool changeDir;
	int dirCount;
	bool movecheck;
	bool leftMove, rightMove, upMove, downMove;
	RECT leftColRc, rightColRc, botColRc, topColRc;
	

};
class Player : public GameObject
{

protected:

	vector<tagTile*> _totalTile;
	PlayerInfo _playerInfo;
	Direction _direction;
	RECT testrc;
	bool Hi = false;
public:
	Player();
	~Player();

	virtual HRESULT init(PlayerName playername);
	virtual void release();
	virtual void update();
	virtual void KeyControl();
	virtual void PlayerStateChange();
	PlayerInfo getPlayerinfo() { return _playerInfo; }
	
};

