#include "stdafx.h"
#include "Sword.h"


Sword::Sword()
{
	_image = IMAGEMANAGER->findImage("Sword");
	EFFECTMANAGER->addEffect("AtkUp", "img/warrior/AtkUp.bmp", 160,42,160,42, 1.0f, 0.04f, 50);
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

			if(PLAYERMANGER->get_vPlayer()[0]->getAtkUp() == false)
			{
				EFFECTMANAGER->play("AtkUp", PLAYERMANGER->get_vPlayer()[0]->getCenter().x +
					40, PLAYERMANGER->get_vPlayer()[0]->getCenter().y - 30);
			}
			PLAYERMANGER->get_vPlayer()[0]->setAtkUp(true);
				
			
				
			
			break;
		}
		else
		{
			_vIPlayer++;
		}
	}

	if (PLAYERMANGER->get_vPlayer()[0]->getAtkUp() == true)
	{
		cout << "참이다" << endl;
	}
	else
	{
		cout << "아니다" << endl;
	}
}
