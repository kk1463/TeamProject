#pragma once
#include "gameNode.h"

class animation;

class effect : public gameNode
{
protected:
	int			_x;
	int			_y;

	image*		_effectImage;
	animation*	_effectAnimation;
	BOOL		_isRunning;
	float		_elapsedTime;
	CALLBACK_FUNCTION_TwoParam _cbFunction;

public:
	effect();
	~effect();

	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime, CALLBACK_FUNCTION_TwoParam cbFunction);
	virtual void release();
	virtual void update();
	virtual void render();

	void startEffect(int x, int y);

	virtual void killEffect();

	BOOL getIsRunning() { return _isRunning; }
};

