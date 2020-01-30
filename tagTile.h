#pragma once

#define TILESIZE 32 // Ÿ�ϻ����� 

//Ÿ�� ������ ���� 20 / ���� 20
#define TILEX 30 // Ÿ�� ����
#define TILEY 30

//Ÿ�� �� ������� 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//Ÿ�ϼ� ����(Ÿ���� ���� �ȷ�Ʈ ���� ����)
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
	CTRL_SAVE,			//���̺� ��ư���� ���� ��
	CTRL_LOAD,			//�ε� ��ư���� ���� ��
	CTRL_TERRAINDRAW,	//���� �׸��� ��ư
	CTRL_OBJDRAW,		//������Ʈ �׸��� ��ư (��, ���ʹ� ��)
	CTRL_GRASS,
	CTRL_ERASER,		//���찳 ��ư (�߸����� ������Ʈ���� ��������)
	CTRL_END,
	CTRL_COL,
	CTRL_COLERASE
};
//���� Ÿ�� == ���� Ŭ���� ����Ÿ�� ������ ������ ����ü
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
	TERRAIN terrain;		//����
	OBJECT obj;				//������Ʈ
	RECT rc;				//��Ʈ
	int terrainFrameX;		//�ͷ��� ��ȣ
	int terrainFrameY;		//�ͷ��� ��ȣ
	int objFrameX;			//�������� ��ȣ
	int objFrameY;			//�������� ��ȣ

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
	float _totalCost;		//�� ���
	float _costFromStart;	//������ġ�κ��� ���� ���
	float _costToGoal;		//���� ���κ��� ���������� ��κ��
public:
	tagTile();
	~tagTile();



	//================= ������ & ������ ==================
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
