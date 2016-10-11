#pragma once
#include "drawfuction.h"
double xpos, ypos;

template <class T_object>
class geometric
{
public:



	virtual void draw()
	{
		T_object drawcolor;
		drawcolor.draw();

	}


};
