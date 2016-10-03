#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


const int width = 800;

const int height = 700;

double xpos, ypos;

float* pixels = new float[width*height * 3];
const int num_lines = 5;

const int num_cir = 20;

class geometric;

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

class geometric
{
public:
	int start_x, start_y;
	int end_x, end_y;
	int x0, y0;
	int radius;
	int a;
	float r=1.0f, g=0.0f, b=0.0f;
	virtual void draw()
	{

	}
	void effect()
	{
		r = 0.0f;
		g = 1.0f;
		b = 0.0f;
	}
};

class Line: public geometric
{
public:
	
	Line()
	{

	}

	Line(const int _a,const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		initialize(_a,_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int _a,const int _start_x, const int _start_y, const int _end_x, const int _end_y)
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

Line *my_lines = new Line[num_lines];


class box : public geometric
{
public:
	box()
	{

	}

	box(const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		initialize(_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}

	void draw()
	{
		drawLine(start_x, start_y, end_x, start_y, 1.0f, 0.0f, 0.0f);
		drawLine(start_x, start_y, start_x, end_y, 1.0f, 0.0f, 0.0f);
		drawLine(start_x, end_y ,end_x, end_y, 1.0f, 0.0f, 0.0f);
		drawLine(end_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};

box my_box;

class circle :public geometric
{
public:
	int err = 0;
	circle()
	{

	}
public:
	circle(const int& _x0,const int& _y0,const int& _radius)
	{
		initialize(_x0,_y0,_radius);
		
	}
	void initialize(const int & _x0,const int& _y0,const int& _radius)
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

class arrow :public geometric
{
public:
    
	arrow()
	{

	}
	arrow(const int _a,const int& _x0, const int& _y0)
	{
		initialize(_a,_x0, _y0);
	}
	void initialize(const int _a,const int& _x0, const int& _y0)
	{
		a = _a;
		x0 = _x0;
		y0 = _y0;
	}
	void draw()
	{
		if (a == 1)//up arrow
		{
			drawLine(x0, y0 - 35, x0, y0 + 35,1.0f,0.0f,0.0f);
			drawLine(x0 - 15, y0 + 20, x0, y0 + 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0 , y0 + 35, x0+15, y0 + 20, 1.0f, 0.0f, 0.0f);
		}
		if (a == 2)//down arrow
		{
			drawLine(x0, y0 - 35, x0, y0 + 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 15, y0 - 20, x0, y0 - 35, 1.0f, 0.0f, 0.0f);
			drawLine(x0 , y0 - 35, x0+15, y0 - 20, 1.0f, 0.0f, 0.0f);
		}
		if (a == 3)//rignt arrow
		{
			drawLine(x0-35, y0, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
			drawLine(x0 +20, y0 - 15, x0+35, y0, 1.0f, 0.0f, 0.0f);
			drawLine(x0 + 20, y0 + 15, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
		}
		if (a == 4)//left arrow
		{
			drawLine(x0 - 35, y0, x0 + 35, y0, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 35, y0, x0 - 20, y0-15, 1.0f, 0.0f, 0.0f);
			drawLine(x0 - 35, y0, x0 - 20, y0 + 15, 1.0f, 0.0f, 0.0f);
		}
		
	}
};
class X :public geometric
{
public:
	X()
	{

	}

	X(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		initialize(_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int _start_x, const int _start_y, const int _end_x, const int _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw()
	{
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
		drawLine(start_x, end_y, end_x, start_y, 1.0f, 0.0f, 0.0f);
	}

};
class A :public geometric
{
public:
public:

	A()
	{

	}
	A( const int& _x0, const int& _y0)
	{
		initialize( _x0, _y0);
	}
	void initialize( const int& _x0, const int& _y0)
	{
		x0 = _x0;
		y0 = _y0;
	}
	void draw()
	{
		drawthickLine(x0 - 25, y0 - 25, x0, y0 + 25, 1.0f, 0.0f, 0.0f);
		drawthickLine(x0, y0 + 25, x0 + 25, y0 - 25, 1.0f, 0.0f, 0.0f);
		drawLine(x0 - 10, y0, x0 + 10, y0, 1.0f, 0.0f, 0.0f);
	}
};

circle **my_circles = new circle*[num_cir];

geometric **my_object = new geometric*[40];

int main(void)
{

	geometric *my_circle = new circle;

	
	

	//initialize circle 0~19
	for (int f = 0; f < 4; f++)
	{
		for (int i = 0; i < 5; i++)
		{

			/*circle *temp = new circle;*/
			my_object[i+5*f] = new circle(100 + 150 * i, 100 + 150 * f,50);
			/*temp->radius = 50;
			temp->x0 = 100 + 150 * i;
			temp->y0 = 100 + 150 * f;

			my_object[i + 5 * f] = temp;*/

		}
	}

	//initialize arrows 1234,11,12,13,14
	for(int f=0;f<2;f++)
		for (int i = 20; i < 24; i++)
		{
			my_object[i + 10 * f] = new arrow(i - 19, 100 + 150 * (i - 20), 100 + 300 * f);
		}
	//initialize box 5,15
	for (int f = 0; f<2; f++)
		{
			my_object[24 + 10 * f] = new box(675,75+300*f,725,125+300*f);
		}
	//initialize thick line 6,16
	for (int f = 0; f<2; f++)
	{
		my_object[25 + 10 * f] = new Line(2,75,225+300*f, 125,275+300*f);
	}

	//initialize inside circle 7,17
	for (int f = 0; f<2; f++)
	{
		my_object[26 + 10 * f] = new circle(250,250+300*f,25);
	}
	//initialize X 8 ,18
	for (int f = 0; f<2; f++)
	{
		my_object[27 + 10 * f] = new X(375, 225 + 300 * f,425,275+300*f);
	}
	//initialize one line 9,19
	for (int f = 0; f<2; f++)
	{
		my_object[28 + 10 * f] = new Line(1,550, 215 + 300 * f, 550, 285 + 300 * f);
	}
	//initialize A10,20
	for (int f = 0; f<2; f++)
	{
		my_object[29 + 10 * f] = new A(700, 250 + 300 * f);
	}
	

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
		//initialize effect.
		for (int f = 0; f < 4; f++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (poscir(xpos, ypos, my_object[i + 5 * f]->x0, 700 - my_object[i + 5 * f]->y0, my_object[i + 5 * f]->radius) < 0.0)
				{
					my_object[i + 5 * f]->effect();
					my_object[i + 5 * f] = new circle(100 + 150 * i, 100 + 150 * f, 50);
				}

			}
		}
		
		for (int i = 0; i < 40; i++)
		{
			my_object[i]->draw();
		}
	
	
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;
	delete[] my_lines;
	glfwTerminate();
	return 0;
}


