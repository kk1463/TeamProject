#pragma once
class progressBar 
{
private:
	RECT _rcProgress;
	float _x, _y;
	float _xx, _yy;
	float _width;

	image* _progressBarTop;			//게이지 앞에 이미지
	image* _progressBarBottom;		//게이지 뒤에 이미지

public:
	progressBar();
	~progressBar();

	HRESULT init(float x, float y, int width, int height, string name, string backName);
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

