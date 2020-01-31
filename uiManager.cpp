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


	_armor = IMAGEMANAGER->addImage("갑옷", "갑옷.bmp", 40, 31, true, RGB(255, 0, 255));
	_ring = IMAGEMANAGER->addImage("반지", "반지.bmp", 30, 30, true, RGB(255, 0, 255));
	_stick = IMAGEMANAGER->addImage("지팡이", "지팡이.bmp", 25, 43, true, RGB(255, 0, 255));
	_knife = IMAGEMANAGER->addImage("칼", "칼.bmp", 40, 40, true, RGB(255, 0, 255));
	_shield = IMAGEMANAGER->addImage("나무방패", "나무방패.bmp", 30, 36, true, RGB(255, 0, 255));


	_inven = IMAGEMANAGER->addImage("Inven", "인벤.bmp", 697, 526, true, RGB(255, 0, 255));

	skillPointer1 = IMAGEMANAGER->addFrameImage("스킬포인터", "스킬포인터.bmp", 116, 58, 2, 1, true, RGB(255, 0, 255));
	_pointer = IMAGEMANAGER->addImage("일반포인터", "일반포인터.bmp", 60, 58, true, RGB(255, 0, 255));
	_pointerX = 270;
	_pointerY = 200;
	_pointer2 = IMAGEMANAGER->addFrameImage("포인터", "포인터.bmp", 120, 58, 2, 1, true, RGB(255, 0, 255));
	_pointerX1 = 230;
	_pointerY1 = 206;

	_itemBox = IMAGEMANAGER->addImage("아이템창", "아이템창.bmp", 117, 106, true, RGB(255, 0, 255));
	_list1 = IMAGEMANAGER->addFrameImage("인벤창", "인벤창.bmp", 200, 91, 2, 1, true, RGB(255, 0, 255));
	_list2 = IMAGEMANAGER->addFrameImage("장비창", "장비창.bmp", 202, 90, 2, 1, true, RGB(255, 0, 255));
	_skillInven = IMAGEMANAGER->addImage("스킬창 배경", "스킬창 배경.bmp", 697, 526, true, RGB(255, 0, 255));
	itemOn = IMAGEMANAGER->addImage("장비창 활성", "장비창 활성.bmp", 619, 212, true, RGB(255, 0, 255));
	itemOff = IMAGEMANAGER->addImage("장비창 비활성", "장비창 비활성.bmp", 619, 213, true, RGB(255, 0, 255));
	worriorOn = IMAGEMANAGER->addImage("전사스킬창 활성", "전사스킬창 활성.bmp", 542, 174, true, RGB(255, 0, 255));
	worriorOff = IMAGEMANAGER->addImage("전사스킬창 비활성", "전사스킬창 비활성.bmp", 542, 175, true, RGB(255, 0, 255));
	goldBar = IMAGEMANAGER->addImage("골드창", "골드창.bmp", 120, 29, true, RGB(255, 0, 255));

	weapon = IMAGEMANAGER->addImage("무기", "무기.bmp", 28, 28, true, RGB(255, 0, 255));
	armor = IMAGEMANAGER->addImage("방어구", "방어구.bmp", 38, 30, true, RGB(255, 0, 255));
	shoes1 = IMAGEMANAGER->addImage("신발", "신발.bmp", 34, 32, true, RGB(255, 0, 255));
	shield = IMAGEMANAGER->addImage("방패", "방패.bmp", 24, 28, true, RGB(255, 0, 255));
	glasses = IMAGEMANAGER->addImage("안경", "안경.bmp", 48, 12, true, RGB(255, 0, 255));
	accessories = IMAGEMANAGER->addImage("엑세서리", "엑세서리.bmp", 30, 30, true, RGB(255, 0, 255));
	hat = IMAGEMANAGER->addImage("투구", "투구.bmp", 32, 22, true, RGB(255, 0, 255));

	worriorSkill1 = IMAGEMANAGER->addImage("전사스킬1", "전사스킬1.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill2 = IMAGEMANAGER->addImage("전사스킬2", "전사스킬2.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill3 = IMAGEMANAGER->addImage("전사스킬3", "전사스킬3.bmp", 65, 69, true, RGB(255, 0, 255));
	worriorSkill4 = IMAGEMANAGER->addImage("전사스킬4", "전사스킬4.bmp", 65, 69, true, RGB(255, 0, 255));
	Skill1 = IMAGEMANAGER->addImage("스킬비활성1", "스킬비활성1.bmp", 64, 64, true, RGB(255, 0, 255));
	Skill2 = IMAGEMANAGER->addImage("스킬비활성2", "스킬비활성2.bmp", 64, 64, true, RGB(255, 0, 255));
	Skill3 = IMAGEMANAGER->addImage("스킬비활성3", "스킬비활성3.bmp", 64, 64, true, RGB(255, 0, 255));
	Skill4 = IMAGEMANAGER->addImage("스킬비활성4", "스킬비활성4.bmp", 64, 64, true, RGB(255, 0, 255));


	hpUi = IMAGEMANAGER->addImage("체력ui", "체력ui.bmp", 401, 177, true, RGB(255, 0, 255));
	frontHp = IMAGEMANAGER->addImage("hpBar", "hpBar.bmp", 252, 14, true, RGB(255, 0, 255));
	mpBar = IMAGEMANAGER->addImage("mpBar", "mpBar.bmp", 226, 14, true, RGB(255, 0, 255));
	backHp = IMAGEMANAGER->addImage("backHp", "backHp.bmp", 252, 14, true, RGB(255, 0, 255));

	select1 = IMAGEMANAGER->addImage("선택창1", "선택창1.bmp", 200, 100, true, RGB(255, 0, 255));
	select2 = IMAGEMANAGER->addImage("선택창2", "선택창2.bmp", 200, 100, true, RGB(255, 0, 255));
	invenSelect1 = IMAGEMANAGER->addImage("인벤선택창1", "인벤선택창1.bmp", 200, 98, true, RGB(255, 0, 255));
	invenSelect2 = IMAGEMANAGER->addImage("인벤선택창2", "인벤선택창2.bmp", 200, 98, true, RGB(255, 0, 255));

	/*for (int i = 0;i < _pm->get_vPlayer().size();i++)
	{
		_playerItemVector.push_back(new uiInfo);
	}*/


	//인벤창 렉트
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

	//아이템창 렉트
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

	//스킬창 렉트
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
		//인벤, 아이템 선택창 출력
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

			//아이템 착용창-> 인벤으로  아이템 이동
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

			//아이템착용창에서 ->인벤창 화면이동 
			if (draw1 == false)
			{
				if (moveCount == 2)
				{
					stay = true;
					move = false;
					item = false;
				}
			}

			//아이템 지우기
			if (invenDraw1 == true)
			{
				if (moveCount == 2)
				{
					//item class 이동
					//_um->getcount();
					//removeItem(i);
				}

			}
		}
		//카운트 = 2 ->화면지움
	if (moveCount == 2)
	{
		move = false;
		draw = false;
		invenDraw = false;
		moveCount = 0;
	}

	//선택창 위아래 이동
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
	//선택창 취소
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

	//스킬당 마나비례 이미지 출력
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
	//플레이어 hp,mp출력
	hpUi->render(getMemDC(), 0, 10);
	PlayerHp->render();
	PlayerMp->Mprender();
	
	//인벤ui 적용
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
		//창 변경 적용
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

			//스킬 선택창 -> 아이템 선택창 이동
			if (stay3 == false)
			{
				itemOn->render(getMemDC(), 210, 150);
				worriorOff->render(getMemDC(), 230, 390);
				
				//아이템포인터
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

		//아이템 미착용 이미지

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

		

		// 아이템 선택창
		if (draw == true )
		{
			select1->render(getMemDC(), _rc3[box1[num1]].left + 90, _rc3[box1[num1]].top);
			if(draw1 == true)
			{
				select2->render(getMemDC(), _rc3[box1[num1]].left + 90, _rc3[box1[num1]].top);
			}
		}
	}

	//아이템 선택창 -> 스킬 선택창 이동
	if (stay3 == true)
	{
		itemOff->render(getMemDC(), 210, 150);
		worriorOn->render(getMemDC(), 230, 390);

		//스킬창 포인터
		for (int k = 0; k < _vSkillPointer.size(); k++)
		{
			if (num2 == k)
			{
				_vSkillPointer[k]->getImage()->frameRender(getMemDC(), _rc4[box2[num2]].left, _rc4[box2[num2]].top, 1, 0);
			}
		}

		//아이템 미착용 이미지
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


	//인벤창 출력
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

		//인벤포인터
		for (int k = 0; k < _vPointer.size(); k++)
		{
			if (num == k)
			{
				_vPointer[k]->getImage()->frameRender(getMemDC(), _rc2[box[num]].left, _rc2[box[num]].top, 1, 0);
			}
		}
		//인벤 선택창
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
							IMAGEMANAGER->findImage("갑옷")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;

						case itemKinds::ring:
							IMAGEMANAGER->findImage("반지")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;

						case itemKinds::knife:
							IMAGEMANAGER->findImage("칼")->render(getMemDC(),
								_playerItemVector[i]->_itemPos[j].x,
								_playerItemVector[i]->_itemPos[j].y);
							break;

						case itemKinds::stick:
							IMAGEMANAGER->findImage("지팡이")->render(getMemDC(),
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
	ui1->init("포인터", PointMake(_pointerX, _pointerY), Pointer);
	_vPointer.push_back(ui1);

	ui* ui2;
	ui2 = new pointer;
	ui2->init("포인터", PointMake(_pointerX1, _pointerY1), Pointer);
	_vPointer.push_back(ui2);

	ui* ui3;
	ui3 = new skillPointer;
	ui3->init("스킬포인터", PointMake(280, 420), Pointer);
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

