#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "drawfuction.h"
#include "geometric.h"
#include "Line.h"
#include "circle.h"
#include "X.h"
#include "vox.h"
#include "a.h"
#include "arrow.h"




//double xpos, ypos;


const int num_lines = 5;

const int num_cir = 20;

class geometric;







//Line *my_lines = new Line[num_lines];




box my_box;







//circle **my_circles = new circle*[num_cir];

geometric **my_object = new geometric*[60];

int main(void)
{

	//geometric *my_circle = new circle;

	
	



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
	
		//initialize circle 0~19
		for (int f = 0; f < 4; f++)
		{
			for (int i = 0; i < 5; i++)
			{		
				my_object[i + 5 * f] = new circle(xpos,ypos,100 + 150 * i, 100 + 150 * f, 50);	
			}
		}
		//initialize bigger circlle
		for (int f = 0; f < 4; f++)
		{
			for (int i = 0; i < 5; i++)
			{
				my_object[i + 5 * (f+8)] = new geometric(xpos, ypos, 100 + 150 * i, 100 + 150 * f, 70);
			}
		}

		//initialize arrows 1234,11,12,13,14
		for (int f = 0; f<2; f++)
			for (int i = 20; i < 24; i++)
			{
				my_object[i + 10 * f] = new arrow(i - 19, 100 + 150 * (i - 20), 100 + 300 * f);
			}
		//initialize box 5,15
		for (int f = 0; f<2; f++)
		{
			my_object[24 + 10 * f] = new box(675, 75 + 300 * f, 725, 125 + 300 * f);
		}
		//initialize thick line 6,16
		for (int f = 0; f<2; f++)
		{
			my_object[25 + 10 * f] = new Line(2, 75, 225 + 300 * f, 125, 275 + 300 * f);
		}

		//initialize inside circle 7,17
		for (int f = 0; f<2; f++)
		{
			my_object[26 + 10 * f] = new geometric(xpos, ypos, 250, 250 + 300 * f, 25);
		}
		//initialize X 8 ,18
		for (int f = 0; f<2; f++)
		{
			my_object[27 + 10 * f] = new X(375, 225 + 300 * f, 425, 275 + 300 * f);
		}
		//initialize one line 9,19
		for (int f = 0; f<2; f++)
		{
			my_object[28 + 10 * f] = new Line(1, 550, 215 + 300 * f, 550, 285 + 300 * f);
		}
		//initialize A10,20
		for (int f = 0; f<2; f++)
		{
			my_object[29 + 10 * f] = new A(700, 250 + 300 * f);
		}

		for (int i = 0; i < 60; i++)
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
	delete[] my_object;
	glfwTerminate();
	return 0;
}


