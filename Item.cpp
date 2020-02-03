#include "stdafx.h"
#include "Item.h"
#include"gameNode.h"

Item::Item()
{
}


Item::~Item()
{
}

void Item::init(POINT ins,float angle)
{
	_isMoving = false;
	setCenter(PointMake(ins.x-_image->getWidth()/2, ins.y - _image->getHeight() / 2));
	_angle = angle;
	_frame = NotFrame;
	_kinds = ITEM;
	_vPlayer = PLAYERMANGER->get_vPlayer();
	_rc = RectMake(ins.x - _image->getWidth() / 2, ins.y - _image->getHeight() / 2, _image->getWidth(), _image->getHeight());
	_count = 0;
}

void Item::collide()
{
	_vIPlayer = _vPlayer.begin();
	RECT temp;
	for (;_vIPlayer != _vPlayer.end();)
	{
		RECT ins = (*_vIPlayer)->getColRect();
		if ((PtInRect(&ins,_center)))
		{
			SCENEMANAGER->getCurrentScene()->deleteObject(this);
			break;
		}
		else
		{
			_vIPlayer++;
		}
	}
}

void Item::render()
{
	RECT temp= _vPlayer[0]->getColRect();
	Rectangle(_backBuffer->getMemDC(), _rc);
	Rectangle(_backBuffer->getMemDC(), temp);
}

void Item::update()
{
	collide();
	if (_isMoving)
	{
		_count++;
		_center.x += cosf(_angle);
		_center.y -= sinf(_angle);
		if (_count > 50)
		{
			_isMoving = false;
		}
	}
}


