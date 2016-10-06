#pragma once

#include "geometric.h"
#include "drawfuction.h"


class A :public geometric
{
public:
public:

	A()
	{

	}
	A(const int& _x0, const int& _y0)
	{
		initialize(_x0, _y0);
	}
	void initialize(const int& _x0, const int& _y0)
	{
		x0 = _x0;
		y0 = _y0;
	}
	void draw()
	{
		drawthickLine(x0 - 25, y0 - 25, x0, y0 + 25, 1.0f, 0.0f, 0.0f);
		drawthickLine(x0, y0 + 25, x0 + 25, y0 - 25, 1.0f, 0.0f, 0.0f);
		drawLine(x0 - 10, y0, x0 + 10, y0, 1.0f, 0.0f, 0.0f);
	}
};
