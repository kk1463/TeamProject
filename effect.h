#pragma once
#include "gameNode.h"

class animation;
class ItemManager;
class effect : public gameNode
{
protected:
	int			_x;
	int			_y;
	int			_itemX;
	int			_itemY;

	image*		_effectImage;
	animation*	_effectAnimation;
	BOOL		_isRunning;
	float		_elapsedTime;
	bool		_makeItem;
	

public:
	effect();
	~effect();

	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime,bool makeItem);
	virtual void release();
	virtual void update();
	virtual void render();

	void startEffect(int x, int y);

	void startEffect(int x, int y, int itemX, int itemY);
	virtual void killEffect();

	BOOL getIsRunning() { return _isRunning; }
};

