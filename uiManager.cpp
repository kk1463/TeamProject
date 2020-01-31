#include "stdafx.h"
#include "uiManager.h"

#include "progressBar.h"



uiManager::uiManager()
{
}


uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{

	PlayerHp = new progressBar;
	PlayerHp->init(124, 37, 252, 14);
	PlayerHp->setGauge(100, 100);

	PlayerMp = new progressBar;
	PlayerMp->Mpinit(150, 75, 226, 14);
	PlayerMp->setGauge(100, 100);


	_armor = IMAGEMANAGER->addImage("����", "����.bmp", 40, 31, true, RGB(255, 0, 255));
	_ring = IMAGEMANAGER->addImage("����", "����.bmp", 30, 30, true, RGB(255, 0, 255));
	_stick = IMAGEMANAGER->addImage("������", "������.bmp", 25, 43, true, RGB(255, 0, 255));
	_knife = IMAGEMANAGER->addImage("Į", "Į.bmp", 40, 40, true, RGB(255, 0, 255));
	_shield = IMAGEMANAGER->addImage("��������", "��������.bmp", 30, 36, true, RGB(255, 0, 255));


	_inven = IMAGEMANAGER->addImage("Inven", "�κ�.bmp", 697, 526, true, RGB(255, 0, 255));

	skillPointer1 = IMAGEMANAGER->addFrameImage("��ų������", "��ų������.bmp", 116, 58, 2, 1, true, RGB(255, 0, 255));
	_pointer = IMAGEMANAGER->addImage("�Ϲ�������", "�Ϲ�������.bmp", 60, 58, true, RGB(255, 0, 255));
	_pointerX = 270;
	_pointerY = 200;
	_pointer2 = IMAGEMANAGER->addFrameImage("������", "������.bmp", 120, 58, 2, 1, true, RGB(255, 0, 255));
	_pointerX1 = 230;
	_pointerY1 = 206;

	_itemBox = IMAGEMANAGER->addImage("������â", "������â.bmp", 117, 106, true, RGB(255, 0, 255));
	_list1 = IMAGEMANAGER->addFrameImage("�κ�â", "�κ�â.bmp", 200, 91, 2, 1, true, RGB(255, 0, 255));
	_list2 = IMAGEMANAGER->addFrameImage("���â", "���â.bmp", 202, 90, 2, 1, true, RGB(255, 0, 255));
	_skillInven = IMAGEMANAGER->addImage("��ųâ ���", "��ųâ ���.bmp", 697, 526, true, RGB(255, 0, 255));
	itemOn = IMAGEMANAGER->addImage("���â Ȱ��", "���â Ȱ��.bmp", 619, 212, true, RGB(255, 0, 255));
	itemOff = IMAGEMANAGER->addImage("���â ��Ȱ��", "���â ��Ȱ��.bmp", 619, 213, true, RGB(255, 0, 255));
	worriorOn = IMAGEMANAGER->addImage("���罺ųâ Ȱ��", "���罺ųâ Ȱ��.bmp", 542, 174, true, RGB(255, 0, 255));
	worriorOff = IMAGEMANAGER->addImage("���罺ųâ ��Ȱ��", "���罺ųâ ��Ȱ��.bmp", 542, 175, true, RGB(255, 0, 255));
	goldBar = IMAGEMANAGER->addImage("���â", "���â.bmp", 120, 29, true, RGB(255, 0, 255));

	weapon = IMAGEMANAGER->addImage("����", "����.bmp", 28, 28, true, RGB(255, 0, 255));
	armor = IMAGEMANAGER->addImage("��", "��.bmp", 38, 30, true, RGB(255, 0, 255));
	shoes1 = IMAGEMANAGER->addImage("�Ź�", "�Ź�.bmp", 34, 32, true, RGB(255, 0, 255));
	shield = IMAGEMANAGER->addImage("����", "����.bmp", 24, 28, true, RGB(255, 0, 255));
	glasses = IMAGEMANAGER->addImage("�Ȱ�", "�Ȱ�.bmp", 48, 12, true, RGB(255, 0, 255));
	accessories = IMAGEMANAGER->addImage("��������", "��������.bmp", 30, 30, true, RGB(255, 0, 255));
	hat = IMAGEMANAGER->addImage("����", "����.bmp", 32, 22, true, RGB(255, 0, 255));

	worriorSkill1 = IMAGEMANAGER->addImage("���罺ų1", "���罺ų1.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill2 = IMAGEMANAGER->addImage("���罺ų2", "���罺ų2.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill3 = IMAGEMANAGER->addImage("���罺ų3", "���罺ų3.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill4 = IMAGEMANAGER->addImage("���罺ų4", "���罺ų4.bmp", 65, 69, true, RGB(255, 0, 255));
	Skill1 = IMAGEMANAGER->addImage("��ų��Ȱ��1", "��ų��Ȱ��1.bmp", 64, 64, true, RGB(255, 0, 255));
	Skill2 = IMAGEMANAGER->addImage("��ų��Ȱ��2", "��ų��Ȱ��2.bmp", 64, 64, true, RGB(255, 0, 255));
	Skill3 = IMAGEMANAGER->addImage("��ų��Ȱ��3", "��ų��Ȱ��3.bmp", 64, 64, true, RGB(255, 0, 255));
	Skill4 = IMAGEMANAGER->addImage("��ų��Ȱ��4", "��ų��Ȱ��4.bmp", 64, 64, true, RGB(255, 0, 255));


	hpUi = IMAGEMANAGER->addImage("ü��ui", "ü��ui.bmp", 401, 177, true, RGB(255, 0, 255));
	frontHp = IMAGEMANAGER->addImage("hpBar", "hpBar.bmp", 252, 14, true, RGB(255, 0, 255));
	mpBar = IMAGEMANAGER->addImage("mpBar", "mpBar.bmp", 226, 14, true, RGB(255, 0, 255));
	backHp = IMAGEMANAGER->addImage("backHp", "backHp.bmp", 252, 14, true, RGB(255, 0, 255));

	select1 = IMAGEMANAGER->addImage("����â1", "����â1.bmp", 200, 100, true, RGB(255, 0, 255));
	select2 = IMAGEMANAGER->addImage("����â2", "����â2.bmp", 200, 100, true, RGB(255, 0, 255));
	invenSelect1 = IMAGEMANAGER->addImage("�κ�����â1", "�κ�����â1.bmp", 200, 98, true, RGB(255, 0, 255));
	invenSelect2 = IMAGEMANAGER->addImage("�κ�����â2", "�κ�����â2.bmp", 200, 98, true, RGB(255, 0, 255));

	/*for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		_playerItemVector.push_back(new uiInfo);
	}*/


	//�κ�â ��Ʈ
	for (int i = 0; i < 12; ++i)
	{
		if (i < 4)
		{

			_rc2[i] = RectMake(270 + i * 150, 200, 60, 58);
		}
		if (i >= 4 && i < 8)
		{
			_rc2[i] = RectMake(270 + (i - 4) * 150, 350, 60, 58);
		}
		if (i >= 8 && i < 12)
		{
			_rc2[i] = RectMake(270 + (i - 8) * 150, 500, 60, 58);
		}
	}

	//������â ��Ʈ
	for (int i = 0; i < 12; ++i)
	{
		if (i < 4)
		{
			_rc3[i] = RectMake(230 + i * 105, 206, 60, 58);
		}
		if (i >= 4 && i < 6)
		{
			_rc3[i] = RectMake(658 + (i - 4) * 90, 206, 60, 58);
		}
		if (i >= 6 && i < 10)
		{
			_rc3[i] = RectMake(230 + (i - 6) * 105, 293, 60, 58);
		}
		if (i >= 10 && i < 12)
		{
			_rc3[i] = RectMake(658 + (i - 10) * 90, 293, 60, 58);
		}
	}

	//��ųâ ��Ʈ
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
		{
			_rc4[i] = RectMake(280 + i * 96, 420, 58, 58);
		}
		if (i >= 5 && i < 10)
		{
			_rc4[i] = RectMake(280 + (i - 5) * 96, 488, 58, 58);
		}
	}


	count = 0;
	box1[num1] = 0;
	HP = 100;
	
	setUi();
	return S_OK;
}

void uiManager::release()
{

}

void uiManager::update()
{

	PlayerHp->update();
	PlayerHp->setGauge(HP, 100);

	PlayerMp->Mpupdate();
	PlayerMp->setGauge(MP, 100);


	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->update();
	}
	uiInfo* ins = new uiInfo;

	/*for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		switch (_pm->get_vPlayer()[i]->getPlayerinfo()->playerName)
		{
		case 0:
			for (int j = 0;j < _pm->get_vPlayer()[i]->getPlayerinfo()->_vPlayerItem.size();j++)
			{
				ins->_itemList.push_back(_pm->get_vPlayer()[i]->getPlayerinfo()->_vPlayerItem[j]);
				ins->_itemPos.push_back(PointMake(280 + (j % 4) * 150, 210 + (j / 4) * 150));
				_playerItemVector[0] = ins;
			}
			break;
		}
	}*/

	if (MP < 100 )
	{
		MP += 0.2;
	}

	
	cout << MP << endl;
	
	if (KEYMANAGER->isOnceKeyDown('N'))
	{
		if (HP >= 0)
		{
			HP -= 10;
		}
		if (MP >= 0)
		{
			MP -= 10;
		}
	}

	/*if (KEYMANAGER->isOnceKeyDown('M'))
	{
		//draw = true;
	}*/
		//�κ�, ������ ����â ���
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			if (stay3 == false)
			{
				draw = true;
			}
			if (stay == true)
			{
				invenDraw = true;
			}
			move = true;
			moveCount += 1;

			//������ ����â-> �κ�����  ������ �̵�
			if (draw1 == true)
			{
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					/*uiInfo* ins = new uiInfo;
					for (int j = 0;j < PLAYERMANGER->get_vPlayer().size(); j++)
						{
							ins->_itemList.push_back(PLAYERMANGER->get_vPlayer()[j]->getplayeri);
							ins->_itemPos.push_back(PointMake(280 + (j % 4) * 150, 210 + (j / 4) * 150));
							_playerItemVector[0] = ins;
						}*/
				}
			}

			//����������â���� ->�κ�â ȭ���̵� 
			if (draw1 == false)
			{
				if (moveCount == 2)
				{
					stay = true;
					move = false;
					item = false;
				}
			}

			//������ �����
			if (invenDraw1 == true)
			{
				if (moveCount == 2)
				{
					//item class �̵�
					//_um->getcount();
					//removeItem(i);
				}

			}
		}
		//ī��Ʈ = 2 ->ȭ������
	if (moveCount == 2)
	{
		move = false;
		draw = false;
		invenDraw = false;
		moveCount = 0;
	}

	//����â ���Ʒ� �̵�
	if (move == true)
	{
		if (KEYMANAGER->isOnceKeyDown('K'))
		{
			draw1 = true;
			invenDraw1 = true;
		}

		if (KEYMANAGER->isOnceKeyDown('I'))
		{
			draw1 = false;
			invenDraw1 = false;
		}
		
	}
	//����â ���
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		draw = false;
		invenDraw = false;
		moveCount += 1;
	}
	keyControl();
}


void uiManager::render()
{
	//shield1->render(getMemDC(), 100, 500);
	/*if(draw == true)
	{
		_knife->render(getMemDC(), 50, 30);
	}*/


	for (_viUi = _vUi.begin(); _viUi != _vUi.end(); ++_viUi)
	{
		(*_viUi)->render();
	}

	//��ų�� ������� �̹��� ���
	if (skill == false)
	{
		if (_noMp == false)
		{
			if (MP >= 12)
			{
				worriorSkill1->render(getMemDC(), 400, 20);
			}
			if (MP >= 15)
			{
				worriorSkill2->render(getMemDC(), 480, 20);
			}
			if (MP >= 20)
			{
				worriorSkill3->render(getMemDC(), 560, 20);
			}
			if (MP >= 25)
			{
				worriorSkill4->render(getMemDC(), 640, 20);
			}
		}
	
			if (MP < 12)
			{
				Skill1->render(getMemDC(), 400, 20);
				_noMp == true;
			}
			if (MP < 15)
			{
				Skill2->render(getMemDC(), 480, 20);
				_noMp == true;
			}
			if (MP < 20)
			{
				Skill3->render(getMemDC(), 560, 20);
				_noMp == true;
			}
					
			if (MP < 25)
			{
				Skill4->render(getMemDC(), 640, 20);
				_noMp == true;
			}
		//}
	}
	//�÷��̾� hp,mp���
	hpUi->render(getMemDC(), 0, 10);
	PlayerHp->render();
	PlayerMp->Mprender();
	
	//�κ�ui ����
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		count += 1;
		stay = true;
		skill = true;
		stay2 = true;
	}
	if (count >= 2)
	{
		stay = false;
		stay2 = false;
		skill = false;
		count = 0;
	}

	if (stay2 == true)
	{
		//â ���� ����
		if (item == false)
		{
			_list1->frameRender(getMemDC(), WINSIZEX / 2 - 100, 10, 1, 0);
			_list2->frameRender(getMemDC(), WINSIZEX / 2, 10, 0, 0);
		}

		if (item == true)
		{
			_list1->frameRender(getMemDC(), WINSIZEX / 2 - 100, 10, 0, 0);
			_list2->frameRender(getMemDC(), WINSIZEX / 2, 10, 1, 0);
			_skillInven->render(getMemDC(), 180, 120);

			//��ų ����â -> ������ ����â �̵�
			if (stay3 == false)
			{
				itemOn->render(getMemDC(), 210, 150);
				worriorOff->render(getMemDC(), 230, 390);
				
				//������������
				for (int k = 0; k < _vPointer.size(); k++)
				{
					if (num1 == k)
					{
						_vPointer[0]->getImage()->frameRender(getMemDC(), _rc3[box1[num1]].left, _rc3[box1[num1]].top, 1, 0);
					}
				}
				_vPointer[0]->getImage()->frameRender(getMemDC(), _rc3[box1[num1]].left, _rc3[box1[num1]].top, 1, 0);
				/*if (draw == true)
				{
					_knife->render(getMemDC(), 240, 218);
				}*/
			}
		}

		//������ ������ �̹���

		//if (draw == false)
		//{
			weapon->render(getMemDC(), 246, 220);
		//}
		shield->render(getMemDC(), 353, 220);
		armor->render(getMemDC(), 450, 220);
		hat->render(getMemDC(), 557, 225);
		accessories->render(getMemDC(), 246, 310);
		accessories->render(getMemDC(), 350, 310);
		shoes1->render(getMemDC(), 450, 305);
		glasses->render(getMemDC(), 550, 315);
		weapon->render(getMemDC(), 675, 220);
		shield->render(getMemDC(), 768, 220);
		hat->render(getMemDC(), 676, 308);
		glasses->render(getMemDC(), 756, 315);

		

		// ������ ����â
		if (draw == true )
		{
			select1->render(getMemDC(), _rc3[box1[num1]].left + 90, _rc3[box1[num1]].top);
			if(draw1 == true)
			{
				select2->render(getMemDC(), _rc3[box1[num1]].left + 90, _rc3[box1[num1]].top);
			}
		}
	}

	//������ ����â -> ��ų ����â �̵�
	if (stay3 == true)
	{
		itemOff->render(getMemDC(), 210, 150);
		worriorOn->render(getMemDC(), 230, 390);

		//��ųâ ������
		for (int k = 0; k < _vSkillPointer.size(); k++)
		{
			if (num2 == k)
			{
				_vSkillPointer[k]->getImage()->frameRender(getMemDC(), _rc4[box2[num2]].left, _rc4[box2[num2]].top, 1, 0);
			}
		}

		//������ ������ �̹���
		weapon->render(getMemDC(), 246, 220);
		shield->render(getMemDC(), 353, 220);
		armor->render(getMemDC(), 450, 220);
		hat->render(getMemDC(), 557, 225);
		accessories->render(getMemDC(), 246, 310);
		accessories->render(getMemDC(), 350, 310);
		shoes1->render(getMemDC(), 450, 305);
		glasses->render(getMemDC(), 550, 315);
		weapon->render(getMemDC(), 675, 220);
		shield->render(getMemDC(), 768, 220);
		hat->render(getMemDC(), 676, 308);
		glasses->render(getMemDC(), 756, 315);
	}


	//�κ�â ���
	if (stay == true)
	{
		_inven->render(getMemDC(), 180, 120);
		_inven->render(getMemDC(), 180, 120);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_itemBox->render(getMemDC(), 240 + i * 150, 180 + j * 150);
				_pointer->render(getMemDC(), 270 + i * 150, 200 + j * 150);
				goldBar->render(getMemDC(), WINSIZEX / 2 + 150, 130);
			}
		}

		//�κ�������
		for (int k = 0; k < _vPointer.size(); k++)
		{
			if (num == k)
			{
				_vPointer[k]->getImage()->frameRender(getMemDC(), _rc2[box[num]].left, _rc2[box[num]].top, 1, 0);
			}
		}
		//�κ� ����â
		if (invenDraw == true)
		{
			invenSelect2->render(getMemDC(), _rc2[box[num]].left+90, _rc2[box[num]].top);
			if (invenDraw1 == true)
			{
				invenSelect1->render(getMemDC(), _rc2[box[num]].left+90, _rc2[box[num]].top);
			}
		}
	}
	

	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		item = true;
		stay = false;
		stay2 = true;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		item = false;
		stay = true;
	}
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		stay3 = true;
	}
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		stay3 = false;
	}

		if (stay == true)
		{
			/*for (int i = 0;i < _playerItemVector.size();i++)
			{
				for (int j = 0;j < _playerItemVector[i]->_itemList.size();j++)
				{
					for (int l = 0;l < _pm->get_vPlayer().size();l++)
					{
						switch (_playerItemVector[i]->_itemList[j]->getItemKinds())
						{
						case itemKinds::armor:
							IMAGEMANAGER->findImage("����")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;

						case itemKinds::ring:
							IMAGEMANAGER->findImage("����")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;

						case itemKinds::knife:
							IMAGEMANAGER->findImage("Į")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;

						case itemKinds::stick:
							IMAGEMANAGER->findImage("������")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;
						}
					}
				}
			}*/
		}
}

void uiManager::setUi()
{
	ui* ui1;
	ui1 = new pointer;
	ui1->init("������", PointMake(_pointerX, _pointerY), Pointer);
	_vPointer.push_back(ui1);

	ui* ui2;
	ui2 = new pointer;
	ui2->init("������", PointMake(_pointerX1, _pointerY1), Pointer);
	_vPointer.push_back(ui2);

	ui* ui3;
	ui3 = new skillPointer;
	ui3->init("��ų������", PointMake(280, 420), Pointer);
	_vSkillPointer.push_back(ui3);
}


void uiManager::keyControl()
{
	if (move == false)
	{
		if (item == false)
		{
			if (KEYMANAGER->isOnceKeyDown('I'))
			{
				if (box[num] >= 4 && box[num] <= 11) box[num] -= 4;
			}
			if (KEYMANAGER->isOnceKeyDown('K'))
			{
				if (box[num] >= 0 && box[num] <= 7) box[num] += 4;
			}
			if (KEYMANAGER->isOnceKeyDown('J'))
			{
				if (box[num] != 0) box[num] -= 1;
			}
			if (KEYMANAGER->isOnceKeyDown('L'))
			{
				if (box[num] != 11) box[num] += 1;
			}
		}

		if (item == true && stay3 == false)
		{
			if (KEYMANAGER->isOnceKeyDown('I'))
			{
				if (box1[num1] >= 6 && box1[num1] <= 11) box1[num1] -= 6;
			}
			if (KEYMANAGER->isOnceKeyDown('K'))
			{
				if (box1[num1] >= 0 && box1[num1] <= 5) box1[num1] += 6;
			}
			if (KEYMANAGER->isOnceKeyDown('J'))
			{
				if (box1[num1] != 0) box1[num1] -= 1;
			}
			if (KEYMANAGER->isOnceKeyDown('L'))
			{
				if (box1[num1] != 11) box1[num1] += 1;
			}
		}

		if (item == true && stay3 == true)
		{

			if (KEYMANAGER->isOnceKeyDown('I'))
			{
				if (box2[num2] >= 5 && box2[num2] <= 9) box2[num2] -= 5;
			}
			if (KEYMANAGER->isOnceKeyDown('K'))
			{
				if (box2[num2] >= 0 && box2[num2] <= 4) box2[num2] += 5;
			}
			if (KEYMANAGER->isOnceKeyDown('J'))
			{
				if (box2[num2] != 0) box2[num2] -= 1;
			}
			if (KEYMANAGER->isOnceKeyDown('L'))
			{
				if (box2[num2] != 9) box2[num2] += 1;
			}
		}
	}
}

void uiManager::HitDamage(float damage)
{
	HP -= damage;
}


bool uiManager::getStay()
{
	return stay;
}

