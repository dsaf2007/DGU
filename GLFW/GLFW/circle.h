#pragma once
#include "geometric.h"
#include "drawfuction.h"

class circle :public geometric
{
public:

	circle()
	{

	}
public:
	circle(const int& _x0, const int& _y0, const int& _radius)
	{
		initialize(_x0, _y0, _radius);

	}
	void initialize(const int & _x0, const int& _y0, const int& _radius)
	{
		x0 = _x0;
		y0 = _y0;
		radius = _radius;
	}
	void draw()
	{
		int x = radius;
		int y = 0;
		while (x >y)
		{

			drawPixel(x0 + x, y0 + y, r, g, b);
			drawPixel(x0 + y, y0 + x, r, g, b);
			drawPixel(x0 - y, y0 + x, r, g, b);
			drawPixel(x0 - x, y0 + y, r, g, b);
			drawPixel(x0 - x, y0 - y, r, g, b);
			drawPixel(x0 - y, y0 - x, r, g, b);
			drawPixel(x0 + y, y0 - x, r, g, b);
			drawPixel(x0 + x, y0 - y, r, g, b);

			y += 1;
			err += 1 + 2 * y;
			if (2 * (err - x) + 1 > 0)
			{
				x -= 1;
				err += 1 - 2 * x;
			}
		}
	}
};
