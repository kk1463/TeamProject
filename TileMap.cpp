#include "stdafx.h"
#include "TileMap.h"
#include"gameNode.h"

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::release()
{
}




void TileMap::loadObj(string FileName,string StageName)
{
	HANDLE file;
	DWORD read;
	OBJSTRUCT ins[100];
	int size = filesize(FileName.c_str());
	file = CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, ins, size, &read, NULL);

	for (int i = 0; i < size / sizeof(OBJSTRUCT); i++)
	{
		bool check = false;
		bool enemyCheck = false;
		switch (ins[i].kinds)
		{
		case HYDRA:
			obj = new Hydra;
			enemyCheck = true;
			break;
		case RABBIT:
			obj = new Rabbit;
			enemyCheck = true;
			break;
		case SLIME:
			obj = new Slime;
			enemyCheck = true;
			break; 
		case FLOWER:
			obj = new Flower;
			enemyCheck = true;
			break;
		case PLAYER:
			check = true;
			break;
		default:
			obj = new GameObject;
			break;
		}
		if (!check)
		{
			settingObj(obj, ins[i]);
		}
		if (enemyCheck)
		{
			ENEMYMANAGER->setEnemy(obj);
		}
		SCENEMANAGER->findScene(StageName)->setGameObj(obj);
		
	}
	CloseHandle(file);
}
std::ifstream::pos_type TileMap::filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}
vector<tagTile*> TileMap::load(string FileName)
{
	HANDLE file;
	DWORD read;
	tagTile ins[TILEX * TILEY];
	_tiles.clear();
	file = CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, ins, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles.push_back(new tagTile);
		(*_tiles[i]) = ins[i];

	}
	
	CloseHandle(file);
	return _tiles;
}
void TileMap::settingObj(GameObject* ins, OBJSTRUCT obj)
{
	ins->setCenter(std::move(obj.center));
	ins->setFrame(std::move(obj.frame));
	ins->setOBJECT(std::move(obj.kinds));
}