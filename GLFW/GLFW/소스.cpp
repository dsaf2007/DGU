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
	vector2d(const T& _x, const T&_y) :x_(_x), y_(_y)
	{
	}
	void print()
	{
		std::cout < x_ << " " << y_ std::endl;
	}
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
	vector2d<int>int_vector(1, 1);
	int_vector.print();
	vector2d<double> double_vector(1, 1);
	double_vector.print();

}


