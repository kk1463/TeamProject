#pragma once

#define TILESIZE 32 // 타일사이즈 

//타일 갯수는 가로 20 / 세로 20
#define TILEX 30 // 타일 갯수
#define TILEY 30

//타일 총 사이즈는 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//타일셋 범위(타일을 찍어올 팔레트 같은 역할)
#define SAMPLETILEX 25
#define SAMPLETILEY 20


#define ATTR_UNMOVE 0x00000001
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};
enum attribute
{
	nonBlocking,
	blocking
};

enum TYPE
{
	TYPE_TERRAIN,
	TYPE_TERRAIN2,
	TYPE_TERRAIN3,
	TYPE_TERRAIN4,
	TYPE_TERRAIN5,
	TYPE_TERRAIN6,
	TYPE_OBJECT,
	TYPE_NONE
};

struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
enum CTRL
{
	CTRL_SAVE,			//세이브 버튼에서 사용될 것
	CTRL_LOAD,			//로드 버튼에서 사용될 것
	CTRL_TERRAINDRAW,	//지형 그리기 버튼
	CTRL_OBJDRAW,		//오브젝트 그리기 버튼 (벽, 에너미 등)
	CTRL_GRASS,
	CTRL_ERASER,		//지우개 버튼 (잘못찍은 오브젝트등을 지움지움)
	CTRL_END,
	CTRL_COL,
	CTRL_COLERASE
};
//현재 타일 == 내가 클릭한 현재타일 정보를 저장할 구조체
struct tagCurrentTile
{
	int x;
	int y;
};
struct OBJSTRUCT
{
	POINT center;
	RECT rc;
	OBJECT kinds;
	frameImage frame;
};

class tagTile
{
private:
	TYPE type;
	TERRAIN terrain;		//지형
	OBJECT obj;				//오브젝트
	RECT rc;				//렉트
	int terrainFrameX;		//터레인 번호
	int terrainFrameY;		//터레인 번호
	int objFrameX;			//ㅇㅂㅈㅌ 번호
	int objFrameY;			//ㅇㅂㅈㅌ 번호

	int indexX;
	int indexY;

	bool isMouseOnMe;

	POINT _center;

	attribute _attribute;
	COLORREF colorWhite;
	COLORREF colorRed;

	tagTile* _parentNode;
	bool _isOpen;


	//F = G + H
	float _totalCost;		//총 비용
	float _costFromStart;	//시작위치로부터 현재 노드
	float _costToGoal;		//현재 노드로부터 도착점까지 경로비용
public:
	tagTile();
	~tagTile();



	//================= 접근자 & 설정자 ==================
	void setType(TYPE tp) { type = tp; }
	TYPE getType() { return type; }


	void setObj(OBJECT obj) { this->obj = obj; }
	OBJECT getObj() { return obj; }

	void setCenter(POINT center) { _center = center; }
	POINT getCenter() { return _center; }

	void setAttribute(attribute str) { _attribute = str; }
	attribute getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }

	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(tagTile* t) { _parentNode = t; }
	tagTile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

	RECT getRect() { return rc; }
	void setRect(RECT rect) { rc = rect; }

	TERRAIN getTerrain() { return terrain; }
	void setTerrain(TERRAIN ter) { terrain = ter; }

	int getTerrainFrameIdx() { return terrainFrameX; }
	void setTerrainFrameIdx(int num) { terrainFrameX = num; }

	int getTerrainFrameIdY() { return terrainFrameY; }
	void setTerrainFrameIdY(int num) { terrainFrameY = num; }

	int getobjFrameX() { return objFrameX; }
	void setobjFrameX(int num) { objFrameX = num; }

	int getobjFrameY() { return objFrameY; }
	void setobjFrameY(int num) { objFrameY = num; }

	int getIdX() { return indexX; }
	void setIdX(int index) {
		indexX = index;
	}
	int getIdY() { return indexY; }
	void setIdY(int index) {
		indexY = index;
	}

	float getX() { return _center.x; }
	void setX(float X) { _center.x = X; }

	float getY() { return _center.y; }
	void setY(float Y) { _center.y = Y; }

};

