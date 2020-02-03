#include "stdafx.h"
#include "Potion.h"


Potion::Potion()
{
	_image = IMAGEMANAGER->findImage("Potion");
	EFFECTMANAGER->addEffect("heal", "img/warrior/heal.bmp", 50, 20, 50, 20, 1.0f, 0.01f, 50);
}


Potion::~Potion()
{
}

void Potion::collide()
{
	_vIPlayer = _vPlayer.begin();        
	RECT temp;
	for (;_vIPlayer != _vPlayer.end();)
	{
		RECT ins = (*_vIPlayer)->getColRect();
		if ((IntersectRect(&temp, &_rc, &ins)))
		{
			ITEMMANAGER->eraseItem(this);
			
			PLAYERMANGER->get_vPlayer()[0]->healed(20);
			EFFECTMANAGER->play("heal", PLAYERMANGER->get_vPlayer()[0]->getCenter().x +
				40, PLAYERMANGER->get_vPlayer()[0]->getCenter().y -30);
			break;
		}
		else
		{
			_vIPlayer++;
		}
	}
}
