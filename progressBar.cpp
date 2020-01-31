#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMakeCenter(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("hpBar", "hpBar.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backHp", "backHp.bmp", width, height, true, RGB(255, 0, 255));
	/*frontHp = IMAGEMANAGER->addImage("hpBar", "hpBar.bmp", 252, 14, true, RGB(255, 0, 255));
	mpBar = IMAGEMANAGER->addImage("mpBar", "mpBar.bmp", 226, 14, true, RGB(255, 0, 255));
	backHp = IMAGEMANAGER->addImage("backHp", "backHp.bmp", 252, 14, true, RGB(255, 0, 255));*/
	//뒤에 깔리는 게이지의 가로크기를 기준으로 삼는다
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
	IMAGEMANAGER->render("backHp", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("hpBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_width, _progressBarBottom->getHeight());


}

HRESULT progressBar::Mpinit(float xx, float yy, int width, int height)
{
	_xx = xx;
	_yy = yy;

	_progressBarTop = IMAGEMANAGER->addImage("mpBar", "mpBar.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backMp", "backMp.bmp", width, height, true, RGB(255, 0, 255));

	_rcProgress = RectMakeCenter(_xx, _yy, width, height);

	//뒤에 깔리는 게이지의 가로크기를 기준으로 삼는다
	_width = _progressBarBottom->getWidth();

	return S_OK;
}

void progressBar::Mprelease()
{
}



void progressBar::Mprender()
{
	IMAGEMANAGER->render("backHp", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_yy + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("mpBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_yy + _progressBarBottom->getHeight() / 2, 0, 0,
		_width, _progressBarBottom->getHeight());

}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();

}
