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
	geometric(const int _xpos, const int _ypos, const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		initialize(_xpos, _ypos,_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int _xpos,const int _ypos,const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		xpos = _xpos;
		ypos = _ypos;
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}

	virtual void draw()
	{
		
		if (xpos >= start_x&&xpos <= end_x&&700-ypos >= start_y&&700-ypos <= end_y)
			{
				drawLine(start_x, start_y, end_x, start_y, 1.0f, 0.0f, 0.0f);
				drawLine(start_x, start_y, start_x, end_y, 1.0f, 0.0f, 0.0f);
				drawLine(start_x, end_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
				drawLine(end_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
			}
			else
			{
				drawLine(start_x, start_y, end_x, start_y, 0.0f, 0.0f, 1.0f);
				drawLine(start_x, start_y, start_x, end_y, 0.0f, 0.0f, 1.0f);
				drawLine(start_x, end_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
				drawLine(end_x, start_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
			}
			

			
		
	
	}


};
