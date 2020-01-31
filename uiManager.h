#pragma once

//#include "item.h"
//#include "itemManager.h"
#include "skillPointer.h"
#include "pointer.h"
//#include "Armor.h"
//#include "Knife.h"
//#include "Money.h"
//#include "Potion.h"
//#include "Ring.h"
//#include "Stick.h"
#include <vector>

class progressBar;

struct uiInfo
{
	//vector<item*> _itemList;
	vector<POINT> _itemPos;

};


class uiManager :public singletonBase<uiManager>
{
private:

	vector<ui*>				_vUi;
	vector<ui*>::iterator	_viUi;

	vector<ui*>				_vPointer;
	vector<ui*>::iterator	_viPointer;

	vector<ui*>				_vSkillPointer;
	vector<ui*>::iterator	_viSkillPointer;
	POINTS pos;
	int _currentFrameX;
	PlayerManager* _pm;
	vector<uiInfo*> _playerItemVector;



	image* _inven;
	bool stay = false;
	image* _itemBox;
	image* _pointer;
	image* _pointer1;
	image* _pointer2;
	int _pointerX, _pointerY;
	int _pointerX1, _pointerY1;
	RECT _rc2[12];
	int box[11];
	int num;
	int count;
	bool item;
	bool stay2;
	bool stay3;
	image* _list1;
	image* _list2;
	image* _skillInven;
	image* itemOn;
	image* itemOff;
	image* wizardOn;
	image* wizardOff;
	image* worriorOn;
	image* worriorOff;
	image* weapon;
	image* armor;
	image* hat;
	image* glasses;
	image* shoes1;
	image* shield;
	image* accessories;
	image* skillPointer1;
	image* itemPointer;
	RECT _rc3[12];
	int box1[12];
	int num1;
	RECT _rc4[10];
	int box2[10];
	int num2;
	image* goldBar;
	image* worriorSkill1;
	image* worriorSkill2;
	image* worriorSkill3;
	image* worriorSkill4;

	image* Skill1;
	image* Skill2;
	image* Skill3;
	image* Skill4;
	image* hpUi;
	image* frontHp;
	image* mpBar;
	image* backHp;
	bool skill;

	int HP = 100;
	float MP = 100;
	progressBar* PlayerHp;
	progressBar* PlayerMp;
	image* _knife;
	bool draw;
	bool draw1;
	bool draw2;
	image* select1;
	image* select2;
	bool _noMp;


public:
	uiManager();
	~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void setUi();
	virtual void keyControl();


	virtual void HitDamage(float damage);



	bool getStay();
};



