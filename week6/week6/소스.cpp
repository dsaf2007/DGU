#include <iostream>
#include <vector>
#include <string>

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

void main()
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



}