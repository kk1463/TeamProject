#include "stdafx.h"
#include "pointer.h"
#include "gameNode.h"

pointer::pointer()
{
}


pointer::~pointer()
{
}

HRESULT pointer::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->findImage(imageName);
	_position.x = position.x;
	_position.y = position.y;

	return S_OK;
}

void pointer::release()
{
}

void pointer::update()
{
}

void pointer::render()
{
	draw();
}

void pointer::draw()
{
	_imageName->render(_backBuffer->getMemDC(), _position.x, _position.y);
}

