#pragma once
#include "image.h"
#include"tagTile.h"
#include"GameObject.h"
#include"PlayerManager.h"




//백버퍼는 어차피 한개만 있으면 되니 전역으로 빼봅시당
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);




class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
public:
	gameNode();
	virtual ~gameNode();

	int _crtSelect;

	//마이크로소프트 전용 디버깅 반환자인데
	//S_OK, E_FAIL, SUCCDED 등으로 초기화가 잘됐는지 아닌지 출력창에 호출함.

	virtual HRESULT init();			//초기화 전용 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render();			//그리기 전용 함수
	virtual void setPlayerManager(PlayerManager* pm) {};
	virtual PlayerManager* getPlayerManager() { return NULL; };
	virtual void setMap();
	virtual vector<tagTile*> getTile();
	virtual vector<GameObject*> getGameObject();

	virtual void save();
	virtual void load();
	virtual void setGameObj(GameObject* obj);
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

