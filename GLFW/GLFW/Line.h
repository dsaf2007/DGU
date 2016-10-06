#pragma once
#include "drawfuction.h"
#include "geometric.h"



class Line : public geometric
{
public:

	Line()
	{

	}

	Line(const int _a, const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		initialize(_a, _start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int _a, const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		a = _a;
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw()
	{
		if (a == 1)//draw normal line
		{
			drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
		}
		if (a == 2)//draw thick line
		{
			drawthickLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
		}
	}

};
