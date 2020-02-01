#include "stdafx.h"
#include "ui.h"
#include "gameNode.h"

ui::ui()
{
}


ui::~ui()
{
}

HRESULT ui::init(const char * imageName, POINT position, uiName name)
{
	_name = name;
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void ui::release()
{

}

void ui::update()
{
}

void ui::render()
{
	draw();
}

void ui::draw()
{
	_imageName->render(_backBuffer->getMemDC(), _position.x, _position.y);
}


