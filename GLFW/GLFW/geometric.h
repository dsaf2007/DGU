#pragma once
#include "drawfuction.h"



class geometric
{
public:
	int start_x, start_y;
	int end_x, end_y;
	int x0, y0;
	int radius;
	int a;
	float r = 1.0f, g = 0.0f, b = 0.0f;
	int err = 0;
	virtual void draw()
	{
		int x = radius;
		int y = 0;
		while (x >y)
		{

			drawPixel(x0 + x, y0 + y, 0.0f, 1.0f, b);
			drawPixel(x0 + y, y0 + x, 0.0f, 1.0f, b);
			drawPixel(x0 - y, y0 + x, 0.0f, 1.0f, b);
			drawPixel(x0 - x, y0 + y, 0.0f, 1.0f, b);
			drawPixel(x0 - x, y0 - y, 0.0f, 1.0f, b);
			drawPixel(x0 - y, y0 - x, 0.0f, 1.0f, b);
			drawPixel(x0 + y, y0 - x, 0.0f, 1.0f, b);
			drawPixel(x0 + x, y0 - y, 0.0f, 1.0f, b);

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
