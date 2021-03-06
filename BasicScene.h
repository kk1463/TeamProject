#pragma once
#include"gameNode.h"
#include"GameObject.h"
#include"Slime.h"
#include"Rabbit.h"
#include"Hydra.h"
#include"Flower.h"
#include"Hydra_W.h"


class BasicScene :public gameNode
{
protected:
	vector<GameObject*> _gameObj;
	vector<GameObject*>::iterator _gameObjIter;
	vector<tagTile*>		 _tiles; // Ÿ�ϸ��ʵ�
	PlayerManager* _pm;
	
	vector<GameObject*> _vItem;
	vector<GameObject*>::iterator _vIItem;



	image* _start;
	image* _clear;

	int _alpha;
	bool _startStop;
	int Stageonecnt;


	bool _Allclear;
	bool _isGameStart = false;
	
public:
	virtual void Start();
	virtual void setGameObj(GameObject* obj);
	void settingObj(GameObject* ins, OBJSTRUCT obj) {};
	virtual void update();
	virtual void render();
	virtual vector<tagTile*> getTile() { return _tiles; }
	virtual vector<GameObject*>& getGameObject();
	virtual void deleteObject(GameObject* ins);
	
	BasicScene();
	~BasicScene();


	bool getGameStart() { return _isGameStart; }
	void setGameStart(bool b) { _isGameStart = b; }
	virtual void eraseGameObj(int num) { _gameObj.erase(_gameObj.begin() + num); }
};

