#pragma once
#include"GameObject.h"
enum ItemKinds
{
	SWORD,
	ARMOR,
	RING,
	COIN,
	POTION,
	SHIELD
};
class Item:public GameObject
{
protected:
	ItemKinds _itemKinds;
	vector<GameObject*> _vPlayer;
	vector<GameObject*>::iterator _vIPlayer;
	RECT _rc;
	float _angle;
	bool _isMoving;
	int _count;
public:
	Item();
	~Item();
	void init(POINT ins, float angle);
	virtual void collide();
	virtual void render();
	virtual void update();

	void setMoving() { _isMoving = true; }
};

