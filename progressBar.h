#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	float _x, _y;
	float _xx, _yy;
	float _width;

	image* _progressBarTop;			//������ �տ� �̹���
	image* _progressBarBottom;		//������ �ڿ� �̹���

public:
	progressBar();
	~progressBar();

	HRESULT init(float x, float y, int width, int height);
	void release();
	void update();
	void render();


	HRESULT Mpinit(float xx, float yy, int width, int height);
	void Mprelease();
	void Mpupdate();
	void Mprender();

	void setGauge(float currentGauge, float maxGauge);

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
};

