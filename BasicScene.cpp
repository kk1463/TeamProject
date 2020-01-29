#include "stdafx.h"
#include "BasicScene.h"


void BasicScene::setGameObj(GameObject* obj)
{
	switch (obj->getObject())
	{
	case PLAYER:
		break;
	case SLIME:
		obj->setimage(IMAGEMANAGER->findImage("Slime"));
		break;
	case RABBIT:
		obj->setimage(IMAGEMANAGER->findImage("Rabbit"));
		break;
	case HYDRA:
		obj->setimage(IMAGEMANAGER->findImage("Hydra"));
		break;
	case FLOWER:
		obj->setimage(IMAGEMANAGER->findImage("Flower"));
		break;
	case Falltree:
		obj->setimage(IMAGEMANAGER->findImage("fall_tree"));
		break;
	case Normal_stone:
		obj->setimage(IMAGEMANAGER->findImage("normal_stone"));
		break;
	case Root:
		obj->setimage(IMAGEMANAGER->findImage("root"));
		break;
	case Tree:
		obj->setimage(IMAGEMANAGER->findImage("tree"));
		break;
	case Winter_tree:
		obj->setimage(IMAGEMANAGER->findImage("winter_tree"));
		break;
	case Marble:
		obj->setimage(IMAGEMANAGER->findImage("marble"));
		break;
	case Bush:
		obj->setimage(IMAGEMANAGER->findImage("bush"));
		break;
	case Ladder_right:
		obj->setimage(IMAGEMANAGER->findImage("ladder_right"));
		break;
	case Ladder_left:
		obj->setimage(IMAGEMANAGER->findImage("ladder_left"));
		break;
	case Rock:
		obj->setimage(IMAGEMANAGER->findImage("rock"));
		break;
	case Big_stone:
		obj->setimage(IMAGEMANAGER->findImage("big_stone"));
		break;
	case Stone:
		obj->setimage(IMAGEMANAGER->findImage("stone"));
		break;
	}
	if (obj->getFrame() != Frame)
	{
		obj->setRect(RectMake(obj->getCenter().x, obj->getCenter().y, obj->getImage()->getWidth(), obj->getImage()->getHeight()));
	}
	else
	{
		obj->setRect(RectMake(obj->getCenter().x, obj->getCenter().y, obj->getImage()->getWidth(), obj->getImage()->getHeight()));
	}
	_gameObj.push_back(obj);
}



void BasicScene::update()
{
	for (int i = 0; i < _gameObj.size(); i++)
	{
		_gameObj[i]->update();
	}
	for (int i = 0; i < _gameObj.size(); i++)
	{
		for (int j = i; j < _gameObj.size(); j++)
		{
			if (_gameObj[i]->getRect().bottom > _gameObj[j]->getRect().bottom)
			{
				GameObject* temp = _gameObj[i];
				_gameObj[i] = _gameObj[j];
				_gameObj[j] = temp;
			}
		}
	}
}

void BasicScene::render()
{
	
	IMAGEMANAGER->findImage("BackGround")->render(getMemDC(), 0, 0);

	for (int i = 0; i < _tiles.size(); ++i)
	{
		if (_tiles[i]->getType() == TYPE_TERRAIN)
		{
			IMAGEMANAGER->frameRender("mapTiles", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN2)
		{
			IMAGEMANAGER->frameRender("Boss_Map_Fall", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN3)
		{
			IMAGEMANAGER->frameRender("Second_Map", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN4)
		{
			IMAGEMANAGER->frameRender("Boss_Map_Summer", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN5)
		{
			IMAGEMANAGER->frameRender("Boss_Map_Winter", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
		else if (_tiles[i]->getType() == TYPE_TERRAIN6)
		{
			IMAGEMANAGER->frameRender("Second_floor", _backBuffer->getMemDC(),
				_tiles[i]->getRect().left,
				_tiles[i]->getRect().top,
				_tiles[i]->getTerrainFrameIdx(),
				_tiles[i]->getTerrainFrameIdY());
		}
	}
	//그리는부분

	for (int i = 0; i < _gameObj.size(); i++)
	{
		if (_gameObj[i]->getFrame() == Frame)
		{
			if ((_gameObj[i]->getObject() == PLAYER) ||
				(_gameObj[i]->getObject() == RABBIT)||
				(_gameObj[i]->getObject() == SLIME)||
				(_gameObj[i]->getObject() == FLOWER)
				)
			{
				_gameObj[i]->getImage()->aniRender(getMemDC(), _gameObj[i]->getCenter().x, _gameObj[i]->getCenter().y, _gameObj[i]->getAni());

			
			}
			else
			{
				_gameObj[i]->getImage()->render(getMemDC(), _gameObj[i]->getCenter().x, _gameObj[i]->getCenter().y);

			}
		}
		else
		{
			_gameObj[i]->getImage()->render(getMemDC(), _gameObj[i]->getCenter().x, _gameObj[i]->getCenter().y);
		}
		
	}

	//콜라이더 확인용
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _tiles.size(); i++)
		{
			if (_tiles[i]->getAttribute() == nonBlocking) continue;
			RectangleMake(_backBuffer->getMemDC(), _tiles[i]->getRect().left, _tiles[i]->getRect().top, TILESIZE, TILESIZE);
		}

		
	}
}

BasicScene::BasicScene()
{
}


BasicScene::~BasicScene()
{
}
