#pragma once
#include"gameNode.h"
#include"GameObject.h"
#include"Slime.h"
#include"Rabbit.h"
#include"Hydra.h"
#include"Flower.h"
#include"Hydra_W.h"

class BasicScene:public gameNode
{
protected:
	vector<GameObject*> _gameObj;
	vector<tagTile*>		 _tiles; // Ÿ�ϸ��ʵ�
	PlayerManager* _pm;
public:
	virtual void setGameObj(GameObject* obj);
	void settingObj(GameObject* ins, OBJSTRUCT obj) {};
	virtual void update();
	virtual void render();
	virtual vector<tagTile*> getTile() { return _tiles; }
	virtual vector<GameObject*> getGameObject();
	BasicScene();
	~BasicScene();
};

