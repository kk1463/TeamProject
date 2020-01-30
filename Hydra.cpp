#include "stdafx.h"
#include "Hydra.h"


Hydra::Hydra()
{
}


Hydra::~Hydra()
{
}

void Hydra::update()
{
	
}

HRESULT Hydra::init()
{
	GameObject::init();
	Enemy::init();
	return S_OK;
}
