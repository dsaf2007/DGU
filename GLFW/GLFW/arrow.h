#pragma once
#include "geometric.h"
#include "drawfuction.h"

class arrow :public geometric
{
public:

	arrow()
	{

	}
	arrow(const int _a, const int& _x0, const int& _y0)
	{
		initialize(_a, _x0, _y0);
	}
	void initialize(const int _a, const int& _x0, const int& _y0)
	{
		a = _a;
		x0 = _x0;
		y0 = _y0;
	}
	void draw()
	{
		if (a == 1)//up arrow
		{
			drawLine(x0, y0 - 35, x0, y0 + 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 15, y0 + 20, x0, y0 + 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0, y0 + 35, x0 + 15, y0 + 20, 1.0f, 0.0f, 0.0f);
		}
		if (a == 2)//down arrow
		{
			drawLine(x0, y0 - 35, x0, y0 + 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 15, y0 - 20, x0, y0 - 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0, y0 - 35, x0 + 15, y0 - 20, 1.0f, 0.0f, 0.0f);
		}
		if (a == 3)//rignt arrow
		{
			drawLine(x0 - 35, y0, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
			drawLine(x0 + 20, y0 - 15, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
			drawLine(x0 + 20, y0 + 15, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
		}
		if (a == 4)//left arrow
		{
			drawLine(x0 - 35, y0, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 35, y0, x0 - 20, y0 - 15, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 35, y0, x0 - 20, y0 + 15, 1.0f, 0.0f, 0.0f);
		}

	}
};
