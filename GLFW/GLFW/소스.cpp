#include <iostream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include <algorithm>
#include "drawfunction.h"
#include "geometric.h"
#include "box.h"
#include "circle.h"

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
	vector2d(const T& _x, const T&_y)
	{
		x_ = _x;
		y_ = _y;

	}
	void print()
	{
		std::cout << x_ << " " << y_ <<std::endl;
	}
};
//double xpos, ypos;

template <class T_object>
class geometricobject:public geometric
{
public:



	virtual void draw()
	{
		T_object drawshape;
		drawshape.draw();

	}


};

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


