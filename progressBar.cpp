#include "stdafx.h"
#include "progressBar.h"
#include"gameNode.h"

progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(float x, float y, int width, int height,string name,string backName)
{
	_x = x;
	_y = y;

	_rcProgress = RectMakeCenter(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->findImage(name);
	_progressBarBottom = IMAGEMANAGER->findImage(backName);

	//�ڿ� �򸮴� �������� ����ũ�⸦ �������� ��´�
	_width = _progressBarBottom->getWidth();


	return S_OK;

}

void progressBar::release()
{
}

void progressBar::update()
{


}

void progressBar::render()
{
	_progressBarTop->render(_backBuffer->getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	_progressBarBottom->render( _backBuffer->getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 
		0, 0,
		_width, _progressBarBottom->getHeight());
	cout << _width << endl;

}

HRESULT progressBar::Mpinit(float xx, float yy, int width, int height)
{
	_xx = xx;
	_yy = yy;

	_progressBarTop = IMAGEMANAGER->addImage("mpBar", "mpBar.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backMp", "backMp.bmp", width, height, true, RGB(255, 0, 255));

	_rcProgress = RectMakeCenter(_xx, _yy, width, height);

	//�ڿ� �򸮴� �������� ����ũ�⸦ �������� ��´�
	_width = _progressBarBottom->getWidth();

	return S_OK;
}

void progressBar::Mprelease()
{
}



void progressBar::Mprender()
{
	IMAGEMANAGER->render("backHp", _backBuffer->getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_yy + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("mpBar", _backBuffer->getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_yy + _progressBarBottom->getHeight() / 2, 0, 0,
		_width, _progressBarBottom->getHeight());

}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
	
}
