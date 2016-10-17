#include <iostream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "drawfunction.h"

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


		drawLine(100, 100, 200, 200, 1.0f, 0.0f, 0.0f);




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


