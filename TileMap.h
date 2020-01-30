#pragma once
#include"EnemyManager.h"
#include <commdlg.h> //OPENFILENAME을 위한 헤더
#include<fstream>
#include"Slime.h"
#include"Rabbit.h"
#include"Hydra.h"
#include"Flower.h"
#include"tagTile.h"

class gameNode;
//TileManger
class TileMap :public singletonBase<TileMap>
{
private:
	vector<tagTile*>		 _tiles; // 타일맵필드
	vector<OBJSTRUCT> _Vobj;
	char* token;					//파일 맵 로드를 위한 토큰
	GameObject* obj;
public:
	void release();
	std::ifstream::pos_type filesize(const char* filename);

	virtual void loadObj(string FileName, string StageName);
	vector<tagTile*> load(string FileName);
	vector<tagTile*> getTotalTile() 
	{ 
		return _tiles;
	}

	void settingObj(GameObject* ins, OBJSTRUCT obj);
	TileMap();
	~TileMap();
};

