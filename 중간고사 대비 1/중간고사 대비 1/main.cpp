#include <vector>
#include <iostream>

template<class Print>
void print(const Print& i)
{
	std::cout << i << std:endl;
}

template <class T>
class vector 
{
public:
	T a, b;
	vector(const T& a_, const T& b_)
	{
		a = a_;
		b = b_;
	}
	void print()
	{
		std::cout << a << " " << b << std::endl;
	}

};
void main()
{
	int a = 3;
	int b = 4;

	std::cout << "the result is " << a << b << std::endl;
	vector<int>int_vector(1, 1);
	int_vector.print();


}