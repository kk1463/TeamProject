#include "stdafx.h"
#include "LoadingScene.h"
#include "progressBar.h"


LoadingScene::LoadingScene()
	: _background(nullptr), _loadingBar(nullptr),
	_currentCount(0)

{
}


LoadingScene::~LoadingScene()
{
}

HRESULT LoadingScene::init()
{
	IMAGEMANAGER->addImage("Hydra", "img/Hydra.bmp", 303, 487, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Player", "img/Player.bmp", 60, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Slime", "img/Slime.bmp", 50, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Rabbit", "img/Rabbit.bmp", 50, 44, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Flower", "img/Flower.bmp", 146, 126, true, RGB(255, 0, 255));
	//����������������������������������������������̹�������������������������������������������������������������������
	_background = IMAGEMANAGER->addImage("Loading", "��׶���_���.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_lodingcall = IMAGEMANAGER->addImage("test", "ǥ��.bmp", 500, 500, true, RGB(255, 0, 255));
	_baegyeong = IMAGEMANAGER->addImage("baegyeong", "����̹���.bmp", 946, 716, true, RGB(255, 0, 255));
	_lodingIcon = IMAGEMANAGER->addImage("Icon", "�ε�.bmp", 388, 64, true, RGB(255, 0, 255));
	_lodingMonster = IMAGEMANAGER->addFrameImage("loadingMonster", "�ε�����.bmp", 756, 99, 9, 1, true, RGB(255, 0, 255));
	_loadingFire = IMAGEMANAGER->addFrameImage("loadingFire", "�ҺҺ�.bmp", 736, 132, 8, 1, true, RGB(255, 0, 255));
	_pressButton = IMAGEMANAGER->addImage("PressButton", "PressStartToSkip.bmp", 791, 105, true, RGB(255, 0, 255));
	//���������������������������������������������������������������������������������������������������������������������

	//��������������������������������ᱸ��������������������������������������������������
	_cloud1 = IMAGEMANAGER->addImage("cloud1", "cloud1.bmp", 465, 195, true, RGB(255, 0, 255));
	_cloud2 = IMAGEMANAGER->addImage("cloud2", "cloud2.bmp", 376, 194, true, RGB(255, 0, 255));
	_cloud3 = IMAGEMANAGER->addImage("cloud3", "cloud3.bmp", 386, 262, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("loadingbar", "loadingBar.bmp", WINSIZEX, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("loadingMaxBar", "loadingMaxBar.bmp", WINSIZEX, 50, true, RGB(255, 0, 255));
	//������������������������������������������������������������������������������������



	//�����������������������ε� �١��������������������������������������
	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 350, WINSIZEX, 50, "loadingbar","loadingMaxBar");
	_loadingBar->setGauge(0, 0);
	//��������������������������������������������������������������������

	//���������������������������������� �ִϸ��̼� �������������������������������
	_loadingAni = new animation;
	_loadingAni->init(_lodingMonster->getWidth(), _lodingMonster->getHeight(), _lodingMonster->getFrameWidth(), _lodingMonster->getFrameHeight());
	_loadingAni->setPlayFrame(1, 9, false, true);
	_loadingAni->setFPS(1);
	_loadingAni->start();
	//�����������������������������������������������������������������������������

	_fire = new animation;
	_fire->init(_loadingFire->getWidth(), _loadingFire->getHeight(), _loadingFire->getFrameWidth(), _loadingFire->getFrameHeight());
	_fire->setPlayFrame(1, 8, false, true);
	_fire->setFPS(1);
	_fire->start();

	//������������������������������ᱸ���̵��������������������������������
	_cloud1x = 100;
	_cloud2x = 700;
	_cloud3x = 100;
	//�������������������������������������������������������������

	//��������������ư ���ķ����� �Ұ��� �̿��� �ε�â ������ԡ������������������
	_swith = false;
	_pressStart = 0;
	_loadingStart = 0;
	//�������������������������������������������������������������


	CreateThread(
		NULL,
		NULL,
		threadFunction,
		this,
		NULL,
		0
	);

	return S_OK;
}

void LoadingScene::release()
{
	SAFE_DELETE(_loadingBar);

}

void LoadingScene::update()
{
	_loadingBar->update();
	_loadingBar->setGauge(_currentCount, LOADINGMAX);

	//����������������������ư�� ���ķ��������������
	_pressStart -= 5;
	_loadingStart -= 5;
	//�����������������������������������������

	//���������������������ε�â�� �ƽ��� �Ǿ����� �����̽��ٸ������� �Ѿ�ԡ����������
	
	//�������������������������������������������������������������������������������

	//�����������ִϸ��̼� �ӵ�������������������������������������������
	_loadingAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_fire->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	//������������������������������������������������������������������

	//����������������������ᱸ�� �̵� ���������������
	if (_cloud1x < -_cloud1->getWidth())
	{
		_cloud1x = WINSIZEX;
	}
	if (_cloud2x < -_cloud2->getWidth())
	{
		_cloud2x = WINSIZEX;
	}
	if (_cloud3x < -_cloud3->getWidth())
	{
		_cloud3x = WINSIZEX;
	}

	_cloud1x -= 1;
	_cloud2x -= 1.7f;
	_cloud3x -= 1.3f;
	if (_currentCount == LOADINGMAX)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			SCENEMANAGER->changeScene("stageOne");
		}
	}
	//�����������������������������������������������������
}

void LoadingScene::render()
{
	_background->render(getMemDC(), 0, 0);

	_cloud1->render(getMemDC(), _cloud1x, 100);
	_cloud2->render(getMemDC(), _cloud2x, 200);
	_cloud3->render(getMemDC(), _cloud3x, 400);

	_baegyeong->render(getMemDC(), 50, 85);
	_loadingFire->aniRender(getMemDC(), 260, -50, _fire);
	if (!_swith)
	{
		_loadingBar->render();
		_lodingIcon->alphaRender(getMemDC(), 400, 800, _loadingStart);
		_lodingMonster->aniRender(getMemDC(), 800, 770, _loadingAni);
	}

	if (_currentCount == LOADINGMAX)
	{
		_swith = true;
		_pressButton->alphaRender(getMemDC(), 200, 830, _pressStart);
	}
}

DWORD threadFunction(LPVOID lpParameter)
{

	LoadingScene* loadHealper = (LoadingScene*)lpParameter;

	while (loadHealper->_currentCount != LOADINGMAX)
	{
		IMAGEMANAGER->addImage("���Ӽ���â", "ĳ���ͼ���â.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
		Sleep(1);

		loadHealper->_currentCount++;
	}
	return 0;
}
