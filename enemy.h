#pragma once
#include "GameObject.h"


class gameNode;

#define FPS 10
enum EnemyState
{
	Idle,
	Run,
	Atk,
	Dmg,
	Dead,
	deadEffect
};

enum BossState
{
	Come,
	Boss_Idle,
	Heading,
	Breath,
	Stun,
	Big,
	Small

};
enum EnemyName
{
	Name_Rabbit,
	Name_Slime,
	Name_Flower,
	Name_Hydra_S, //여름
	Name_Hydra_F, //가을
	Name_Hydra_W  //겨울
};

enum direction
{
	LEFT,
	RIGHT,
	DOWN,
	UP
};

struct info
{
	RECT rc;
	RECT senseRC;
	float x, y;
	image* img;
	direction dir;
	EnemyName name;
	EnemyState state;
	BossState _BossState;
	animation* Ani;
	bool changeAni;
	int fps;
	float SPEED;
	bool leftMove, rightMove, upMove, downMove;  //타일에 충돌했을때 각 방향으로의 움직임을 막아줌
	RECT colRc, leftColRc, rightColRc, botColRc, topColRc; //전후좌우 충돌체크용 렉트
	int HP;

};

class Enemy : public GameObject
{
	vector<GameObject*>  _vPlayer;

protected:
	info en;
	vector<tagTile*> _tiles;

public:
	Enemy();
	~Enemy();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void hit();
	
	virtual void setTile(vector<tagTile*> ins);
	RECT GetEnColRc() { en.colRc; }
	
};

