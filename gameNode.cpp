#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{

	_hdc = GetDC(_hWnd);
	_managerInit = false;

	
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TXTDATA->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		ENEMYMANAGER->init();
		UIMANAGER->init();

	}

	return S_OK;
}

void gameNode::Start()
{
}

void gameNode::release()
{
	if (_managerInit)
	{
		KillTimer(_hWnd, 1);
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		TXTDATA->release();
		TXTDATA->releaseSingleton();
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		KEYANIMANAGER->release();
		KEYANIMANAGER->releaseSingleton();
		TILEMANAGER->release();
		TILEMANAGER->releaseSingleton();
		ENEMYMANAGER->releaseSingleton();
		PLAYERMANGER->releaseSingleton();
		UIMANAGER->release();
		UIMANAGER->releaseSingleton();
	}

	ReleaseDC(_hWnd, _hdc);
}

void gameNode::update()
{
	InvalidateRect(_hWnd, NULL, false);
	SOUNDMANAGER->update();
	TIMEMANAGER->update();
}

void gameNode::render()
{

}

void gameNode::setMap()
{
}

vector<tagTile*> gameNode::getTile()
{

	return vector<tagTile*>();
}

vector<GameObject*>& gameNode::getGameObject()
{
	vector<GameObject*> temp;
	return temp;
}



void gameNode::save()
{
}

void gameNode::load()
{
}

void gameNode::setGameObj(GameObject* obj)
{
}

void gameNode::eraseGameObj(int num)
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
		case WM_CREATE:

		break;
		case WM_PAINT:
		{
			this->render();
		}
		break;
		case WM_TIMER:
			this->update();
		break;

		//목이 아파서 잠시 주석으로 남김 감기조심해라
		//굳이 이렇게 하는 이유는 옛날에는 스테이지 기획을 기획자들이 하다보니
		//MFC 등으로 빠르게 맵툴을 만들어서 기획파트에 넘겨주는 일이 다반사였음
		//그래서 심미적요인을 빼고 빠르게 기능만 탑재해서 넘겼었음.
		//굳이 윈도우 메시지를 사용하지 않고 우리 평소에 하던대로 하면 
		//이런 난리는 안쳐도 됩니당
		case WM_LBUTTONDOWN:
			_leftButtonDown = true;
		break;
		case WM_LBUTTONUP:
			_leftButtonDown = false;
		break;
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>(LOWORD(lParam));
			_ptMouse.y = static_cast<float>(HIWORD(lParam));

		break;

		
		break;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
					PostQuitMessage(0);
				break;

			}
		}
		break;


		case WM_DESTROY:
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
