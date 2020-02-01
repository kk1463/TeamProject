#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

void Item::init(POINT ins)
{
	setCenter(ins);
	_frame = NotFrame;
	_kinds = ITEM;
}
