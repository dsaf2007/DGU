#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


const int width = 800;

const int height = 350;

double xpos, ypos;

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



void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)

{

	pixels[(i + width* j) * 3 + 0] = red;

	pixels[(i + width* j) * 3 + 1] = green;

	pixels[(i + width* j) * 3 + 2] = blue;

}


void drawcircle(double x0, double y0, double radius)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		if (poscir(xpos, 350 - ypos, x0, y0, radius) >= 0.0)
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
		else
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

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}
void drawcircle2(int x0, int y0, double radius)
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


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		std::fill_n(pixels, width*height * 3, 1.0f);


		glfwGetCursorPos(window, &xpos, &ypos);
		//icon1
		drawcircle2(100, 100, 50);
		drawLine(100, 65, 100, 135, 1.0f, 0.0f, 0.0f);
		drawLine(85, 120, 100, 135, 1.0f, 0.0f, 0.0f);
		drawLine(100, 135, 115, 120, 1.0f, 0.0f, 0.0f);
		//icon 2
		drawcircle2(250, 100, 50);
		drawLine(250, 65, 250, 135, 1.0f, 0.0f, 0.0f);
		drawLine(235, 80, 250, 65, 1.0f, 0.0f, 0.0f);
		drawLine(250, 65, 265, 80, 1.0f, 0.0f, 0.0f);
		//icon3
		drawcircle2(400, 100, 50);

		drawLine(365, 100, 435, 100, 1.0f, 0.0f, 0.0f);
		drawLine(365, 100, 380, 115, 1.0f, 0.0f, 0.0f);
		drawLine(365, 100, 380, 85, 1.0f, 0.0f, 0.0f);

		//icon4
		drawcircle2(550, 100, 50);
		drawLine(515, 100, 585, 100, 1.0f, 0.0f, 0.0f);
		drawLine(570, 115, 585, 100, 1.0f, 0.0f, 0.0f);
		drawLine(570, 85, 585, 100, 1.0f, 0.0f, 0.0f);
		//icon5
		drawcircle2(700, 100, 50);
		drawthickLine(675, 75, 725, 125, 1.0f, 0.0f, 0.0f);

		//icon6
		drawcircle2(100, 250, 50);

		drawLine(75, 225, 75, 275, 1.0f, 0.0f, 0.0f);
		drawLine(125, 225, 125, 275, 1.0f, 0.0f, 0.0f);
		drawLine(75, 225, 125, 225, 1.0f, 0.0f, 0.0f);
		drawLine(75, 275, 125, 275, 1.0f, 0.0f, 0.0f);

		//icon7
		drawcircle2(250, 250, 50);
		drawLine(250, 215, 250, 285, 1.0f, 0.0f, 0.0f);
		//icon8
		drawcircle2(400, 250, 50);
		for (int x = 375; x<425; x++)
			for (int y = 225; y < 275; y++)
			{
				if (insidecir(x, y, 400, 250, 25) == false)
					drawPixel(x, y, 1.0f, 0.0f, 0.0f);
			}
		for (int x = 375; x<425; x++)
			for (int y = 225; y < 275; y++)
			{
				if (insidecir(x, y, 400, 250, 20) == false)
					drawPixel(x, y, 1.0f, 1.0f, 1.0f);
			}

		//icon9
		drawcircle2(550, 250, 50);
		drawthickLine(525, 225, 550, 275, 1.0f, 0.0f, 0.0f);
		drawthickLine(550, 275, 575, 225, 1.0f, 0.0f, 0.0f);
		drawLine(540, 250, 560, 250, 1.0f, 0.0f, 0.0f);

		//icon10
		drawcircle2(700, 250, 50);
		drawLine(675, 225, 725, 275, 1.0f, 0.0f, 0.0f);
		drawLine(675, 275, 725, 225, 1.0f, 0.0f, 0.0f);




		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;
	glfwTerminate();
	return 0;
}


