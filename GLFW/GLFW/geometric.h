#pragma once
#include "drawfuction.h"
double xpos, ypos;


class geometric
{
public:
	int start_x, start_y;
	int end_x, end_y;
	int x0, y0;
	int radius;
	int r = 1.0f, g = 0.0f, b = 0.0f;
	int a;

	
	int err = 0;

	geometric()
	{

	}
	geometric(const double& _xpos, const double& _ypos, const int& _x0, const int& _y0, const int& _radius)
	{
		initialize(_xpos,_ypos,_x0, _y0, _radius);

	}
	void initialize(const double& _xpos,const double& _ypos,const int & _x0, const int& _y0, const int& _radius)
	{
		xpos = _xpos;
		ypos = _ypos;
		x0 = _x0;
		y0 = _y0;
		radius = _radius;
	}

	virtual void draw()
	{
		int x = radius;
		int y = 0;
		while (x >y)
		{
		/*	if (poscir(xpos,700- ypos, x0, y0, radius) < 0.0f)
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
			{*/
				drawPixel(x0 + x, y0 + y, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 + y, y0 + x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - y, y0 + x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - x, y0 + y, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - x, y0 - y, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 - y, y0 - x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 + y, y0 - x, 1.0f, 0.0f, 0.0f);
				drawPixel(x0 + x, y0 - y, 1.0f, 0.0f, 0.0f);
			

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
