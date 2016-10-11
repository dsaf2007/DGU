#pragma once
#include <stdbool.h>

const int width = 800;

const int height = 700;

float* pixels = new float[width*height * 3];
bool insidecir(const double x, const double y, const int x_c, const int y_c, const int r)
{



	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f >= 0.0&&f<1000.0)return true;
	else return false;
}


double poscir(double x, double y, const double x_c, const double y_c, const double r)
{



	double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	return f;
}

bool possquare(double xpos,double ypos,double x, double y, const double x_c, const double y_c)
{

	if (xpos >= x&&xpos <= x_c&&ypos >= y&&ypos <= y_c)
		return true;
	else
		return false;

}



void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)

{

	pixels[(i + width* j) * 3 + 0] = red;

	pixels[(i + width* j) * 3 + 1] = green;

	pixels[(i + width* j) * 3 + 2] = blue;

}


void drawcircle(double x0, double y0, int radius)
{




}
void drawcircle2(int x0, int y0, int radius)
{
	drawcircle(x0, y0, radius);
	drawcircle(x0, y0, radius + 0.2);
	drawcircle(x0, y0, radius + 0.4);
	drawcircle(x0, y0, radius + 0.6);
	drawcircle(x0, y0, radius + 0.8);
	drawcircle(x0, y0, radius + 1.0);
	drawcircle(x0, y0, radius + 1.2);
	drawcircle(x0, y0, radius + 1.4);
	drawcircle(x0, y0, radius + 1.6);
	drawcircle(x0, y0, radius + 1.8);
	drawcircle(x0, y0, radius + 2.0);
	drawcircle(x0, y0, radius + 2.2);
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html

// see 'Rasterization' part.

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)

{
	if (i1 == i0)
	{
		for (int j = j0; j <= j1; j++)
		{
			const int i = i1;


			drawPixel(i, j, red, green, blue);
		}
	}
	if (j1 == j0)
	{
		for (int i = i0; i <= i1; i++)
		{
			const int j = j1;


			drawPixel(i, j, red, green, blue);
		}
	}if (i0 != i1&&j0 != j1)
	{
		for (int i = i0; i <= i1; i++)

		{

			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;


			drawPixel(i, j, red, green, blue);
		}

	}

}
void drawthickLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)

	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;


		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0; i <= i1; i++)

	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;


		drawPixel(i + 1, j, red, green, blue);
	}
	for (int i = i0; i <= i1; i++)

	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;


		drawPixel(i - 1, j, red, green, blue);
	}
}

void box(const int start_x, const int start_y, const int end_x, const int end_y,const float red,const float blue,const float green)
{
	//drawLine(start_x, start_y, end_x, start_y, red, blue, green);
	//drawLine(start_x, start_y, start_x, end_y, red, blue, green);
	//drawLine(start_x, end_y, end_x, end_y, red, blue, green);
	//drawLine(end_x, start_y, end_x, end_y, red, blue, green);

	for (int i = 0; i < end_x-start_x; i++)
	{
		drawLine(start_x+i, start_y, start_x+i, end_y, red, blue, green);
	}
}
