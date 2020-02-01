#pragma once
enum frameImage
{
	Frame,
	NotFrame
};
enum OBJECT
{
	HYDRA, RABBIT, FLOWER, SLIME,
	PLAYER,
	Falltree,
	Normal_stone,
	Root,
	Tree,
	Winter_tree,
	Marble,
	Bush,
	Ladder_right,
	Ladder_left,
	Rock,
	Big_stone,
	Stone,
	ITEM,
	OBJ_NONE
};
class GameObject
{
protected:
	frameImage _frame;
	image* _image;
	OBJECT _kinds;
	POINT _center;
	RECT _rc, _colRc;
	
	RECT _playerRC;
	RECT _PlayerAtkRc;	//player용 공격시 나오는 렉트

	RECT en_colRc;		 //enemy용 체크렉트
	RECT en_rightColRc;	 //enemy용 체크렉트
	RECT en_leftColRc;	 //enemy용 체크렉트
	RECT en_topColRc;	 //enemy용 체크렉트
	RECT en_botColRc;	 //enemy용 체크렉트
	RECT EnemyRc;

	int _frameX;
	int _frameY;
	animation* _ani;
	int playerDir;
	int EnemyDir;

	int PlayerDmg;


public:
	GameObject();
	~GameObject();


	virtual void update();
	virtual HRESULT init();
	virtual HRESULT init(POINT pos, int FPS, float SPEED);
	void setFrame(frameImage fm) { _frame = fm; }
	frameImage getFrame() { return _frame; }

	void setimage(image* im) { _image = im; }
	image* getImage() { return _image; }

	void setOBJECT(OBJECT obj) { _kinds = obj; }
	OBJECT getObject() { return _kinds; }

	void setCenter(POINT centerPoint) { _center = centerPoint; }
	POINT getCenter() { return _center; }

	RECT getRect() { return _rc; }
	void setRect(RECT rc) { _rc = rc; }

	RECT getPlayerAtkRc() { return _PlayerAtkRc; }
	void SetPlayerAtkRc(RECT rc) { _PlayerAtkRc=rc; }
	
	RECT getPlayerRect() { return _playerRC; }
	void setPlayerRect(RECT rc) { _playerRC = rc; }

	RECT getEnemyRect() { return EnemyRc; }
	void setEnemyRect(RECT rc) { EnemyRc = rc; }


	//enemy용//
	RECT getColRect() { return _colRc; }
	void setColRect(RECT colRc) { _colRc = colRc; }
	RECT getCheckRect_Left() { return en_leftColRc; }
	void setCheckRect_Left(RECT _en_leftColRc) { en_leftColRc = _en_leftColRc; }
	RECT getCheckRect_Right() { return en_rightColRc; }
	void setCheckRect_Right(RECT _en_rightColRc) { en_rightColRc = _en_rightColRc; }
	RECT getCheckRect_Top() { return en_topColRc; }
	void setCheckRect_Top(RECT _en_topColRc) { en_topColRc = _en_topColRc; }
	RECT getCheckRect_Bottom() { return en_botColRc; }
	void setCheckRect_Bottom(RECT _en_botColRc) { en_botColRc = _en_botColRc; }

	int getPlayerDmg() { return PlayerDmg; }
	void setPlayerDmg(int a) { PlayerDmg = a; }

	int getPlayerDir() { return playerDir; }
	void setPlayerDir(int a) { playerDir = a; }

	int getEnemyDir() { return EnemyDir; }
	void setEnemyDir(int dir) { EnemyDir = dir; }

	virtual void attaked(int atk);
	virtual int getHp() { return 0; }

	void setAni(animation* ani) { _ani = ani; }
	animation* getAni() { return _ani; }



};


