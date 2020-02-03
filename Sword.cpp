#include "stdafx.h"
#include "Sword.h"


Sword::Sword()
{
	_image = IMAGEMANAGER->findImage("Sword");
	EFFECTMANAGER->addEffect("AtkUp", "img/warrior/AtkUp.bmp", 160,42,160,42, 1.0f, 0.01f, 50);
}


Sword::~Sword()
{
}

void Sword::collide()
{

	_vIPlayer = _vPlayer.begin();
	RECT temp;
	for (;_vIPlayer != _vPlayer.end();)
	{
		RECT ins = (*_vIPlayer)->getColRect();
		if ((IntersectRect(&temp, &_rc, &ins)))
		{
			ITEMMANAGER->eraseItem(this);

			
			EFFECTMANAGER->play("AtkUp", PLAYERMANGER->get_vPlayer()[0]->getCenter().x +
				40, PLAYERMANGER->get_vPlayer()[0]->getCenter().y - 30);
			break;
		}
		else
		{
			_vIPlayer++;
		}
	}
}
