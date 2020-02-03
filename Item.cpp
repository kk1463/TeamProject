#include "stdafx.h"
#include "Item.h"
#include"gameNode.h"

Item::Item()
{
}


Item::~Item()
{
}

void Item::init(POINT ins)
{
	setCenter(ins);
	_frame = NotFrame;
	_kinds = ITEM;
	_vPlayer = PLAYERMANGER->get_vPlayer();
	_rc = RectMake(ins.x, ins.y, _image->getWidth(), _image->getHeight());
}

void Item::collide()
{
	_vIPlayer = _vPlayer.begin();
	RECT temp;
	for (;_vIPlayer != _vPlayer.end();)
	{
		RECT ins = (*_vIPlayer)->getColRect();
		if ((IntersectRect(&temp, &_rc, &ins)))
		{
			ITEMMANAGER->eraseItem(this);
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
}


