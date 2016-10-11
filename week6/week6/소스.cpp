#include <iostream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "drawfuction.h"
#include "geometric.h"
#include "red.h"
#include "yellow.h"

template <class T_Class>
void print(const T_Class& i)
{
	std::cout << i << std::endl;
}
template <class T>
class vector2d
{
public:
	T x_, y_;
};








//double xpos, ypos;


const int num_lines = 5;

const int num_cir = 20;

//class geometric;







//Line *my_lines = new Line[num_lines];




//geometric **my_object = new geometric*[2];

int main(void)
{
	/*print(1);
	print(1.1f);
	print("hello world");*/
	vector2d<int> my_vector;
	vector2d<double> my_vector2;
	vector2d<float> my_vector3;

	my_vector.x_ = 1;
	my_vector.y_ = 2;

	my_vector2.x_ = 2.0;
	my_vector2.y_ = 3.0;

	my_vector3.x_ = 1.0f;
	my_vector3.y_ = 1.0f;



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

	geometric<yellow>go_yellow;
	geometric<red>go_red;



	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		std::fill_n(pixels, width*height * 3, 1.0f);



		//glfwGetCursorPos(window, &xpos, &ypos);

	
		//for (int i = 0; i < 60; i++)
		//{
		//	my_object[i]->draw();
		//}
		go_yellow.draw();
		go_red.draw();

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;
	/*delete[] my_object;*/
	glfwTerminate();
	return 0;
}


