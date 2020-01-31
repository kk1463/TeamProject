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
	bool movecheck; //��+��, ��+�Ʒ� �������� ����

	bool atkNoMove; //���ݵ��߿� �������̰� ������ִ°�

	bool atkState; //���ݵ����λ���, �ִϷ������� ������ �ѹ��� ��������ֱ����� ���
	int atkCount = 0;	//����ī��Ʈ, ī��Ʈ�� ������ ���ݻ��°� false�� �ٲ�
	bool leftMove, rightMove, upMove, downMove;  //Ÿ�Ͽ� �浹������ �� ���������� �������� ������
	RECT colRc, leftColRc, rightColRc, botColRc, topColRc; //�����¿� �浹üũ�� ��Ʈ
	RECT AtkRc;

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
	bool EnemyAttacked = false;
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
	void getPlayerDir() { _playerInfo.direction; }//enemy ���������� �ϳ�..

};

