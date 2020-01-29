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
	OBJ,
	OBJ_NONE							//나중에 지울용도
};

class GameObject
{
protected:
	frameImage _frame;
	image* _image;
	OBJECT _kinds;
	POINT _center;
	RECT _rc;
	int _frameX;
	int _frameY;
	animation* _ani;

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

	void setAni(animation* ani) { _ani = ani; }
	animation* getAni() { return _ani; }
};


