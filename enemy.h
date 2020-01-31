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

enum State //상태패턴용 
{
	move1,
	atk1,
	hit1,
	dead1
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
	State _enState;
	image* img;
	direction dir;
	EnemyName name;
	EnemyState state;
	BossState _BossState;
	animation* Ani;
	bool changeAni;
	bool hit, move, atk, dead,angry;
	int fps;
	float SPEED;
	bool leftMove, rightMove, upMove, downMove;  //타일에 충돌했을때 각 방향으로의 움직임을 막아줌
	RECT colRc, leftColRc, rightColRc, botColRc, topColRc; //전후좌우 충돌체크용 렉트
	float hp;
	int Movecheck;
	int count;

};

class Enemy : public GameObject
{


	vector<GameObject*> _vPlayer;


protected:
	info en;
	vector<tagTile*> _tiles;
	float getPlayerPos, getPlayerAngle;

public:
	Enemy();
	~Enemy();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void hit();

	virtual void attaked(int atk);

	virtual void setTile(vector<tagTile*> ins);
	RECT GetEnColRc() { en.colRc; }

	//hp 게터 세터
	void getHp() { en.hp; }
	void setHP(int _hp) { en.hp = _hp; }

};

