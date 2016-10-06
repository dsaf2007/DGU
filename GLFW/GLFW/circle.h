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
	circle(const double& _xpos, const double& _ypos,const int& _x0, const int& _y0, const int& _radius)
	{
		initialize(_xpos,_ypos,_x0, _y0, _radius);

	}
	void initialize(const double& _xpos, const double& _ypos,const int & _x0, const int& _y0, const int& _radius)
	{
		xpos = _xpos;
		ypos = _ypos;
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

			if (poscir(xpos, 700 - ypos, x0, y0, radius) < 0.0f)
			{
				drawPixel(x0 + x, y0 + y, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 + y, y0 + x, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 - y, y0 + x, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 - x, y0 + y, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 - x, y0 - y, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 - y, y0 - x, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 + y, y0 - x, 0.0f, 1.0f, 0.0f);
				drawPixel(x0 + x, y0 - y, 0.0f, 1.0f, 0.0f);
			}
			else
			{
				drawPixel(x0 + x, y0 + y, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 + y, y0 + x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - y, y0 + x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - x, y0 + y, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - x, y0 - y, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - y, y0 - x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 + y, y0 - x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 + x, y0 - y, 1.0f, 0.0f, 0.0f);
			}

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
