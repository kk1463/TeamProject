#pragma once
#include "GameObject.h"
class gameNode;
#define FPS 10


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
	bool movecheck; //오+왼, 위+아래 눌렀을때 멈춤

	bool atkNoMove; //공격도중에 못움직이게 만들어주는값

	bool atkState; //공격도중인상태, 애니렌더에서 공격을 한번만 실행시켜주기위해 사용
	int atkCount = 0;	//공격카운트, 카운트가 끝나면 공격상태가 false로 바뀜
	bool leftMove, rightMove, upMove, downMove;  //타일에 충돌했을때 각 방향으로의 움직임을 막아줌
	RECT colRc, leftColRc, rightColRc, botColRc, topColRc; //전후좌우 충돌체크용 렉트
	RECT AtkRc;
	RECT miniColRc;
	int hp;
	int dmgCount = 0;
	bool attcked = false;
	int playerDirNum;
	float nuckBack;
	image* Num;

};
class Player : public GameObject
{
protected:
	int _tileIdx;
	vector<GameObject*> _vEnemy;
	vector<tagTile*> _totalTile;
	PlayerInfo _playerInfo;
	Direction _direction;
	RECT testrc;
	bool _playerDie;
	bool EnemyAttacked = false;
	image* number;
	bool A = false;
	
	

public:
	Player();
	~Player();

	virtual HRESULT init();
	virtual HRESULT init(PlayerName playername);
	virtual void release();
	virtual void update();
	virtual void KeyControl();
	virtual void PlayerStateChange();
	virtual void PlayerRectChange();
	PlayerInfo getPlayerinfo() { return _playerInfo; }
	RECT getColRc() { return _playerInfo.colRc; }
	RECT getAtkRc() { return _playerInfo.AtkRc; }
	RECT getminiColRc() { return _playerInfo.miniColRc; }
	void getPlayerDir() { _playerInfo.direction; }//enemy 판정을위해 하나..
	virtual int getHp() { return  _playerInfo.hp; }

	void setPlayerHp(int hp) { _playerInfo.hp = hp; }
	virtual void attaked(int atk);
	
};

