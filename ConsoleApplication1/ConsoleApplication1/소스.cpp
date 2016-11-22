#include <iostream>
#include <vector>

class test
{
public:
	void(test::*callback_)() = nullptr;

	void exec()
	{
		if (callback_ != nullptr)
		{
			(this->*callback_)();
		}
	}


	void circle()
	{
		std::cout << "circle" << std::endl;
	}

	void box()
	{
		std::cout << "box" << std::endl;
	}
};

void main()
{
	test draw1;
	draw1.callback_ = &test::circle;
	test draw2;
	draw2.callback_ = &test::box;

	std::vector<test*>obj;
	obj.push_back(new test(draw1));
	obj.push_back(new test(draw2));

	for (auto itr : obj)
	{
		itr->exec();
	}
}