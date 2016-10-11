#include <iostream>
#include <vector>
#include <string>

template <class T_Class>
void print(const T_Class& i)
{
	std::cout << i << std::endl;
}

void main()
{
	print(1);
	print(1.1f);
	print("hello world");

}