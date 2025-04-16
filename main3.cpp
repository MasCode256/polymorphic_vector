#include <stdexcept>
#include <iostream>

#include "polymorphic_vector.hpp"

class Basic
{
public:
	virtual void method() const
	{
		throw std::runtime_error("method Basic.method() haven't implementation.");
	}
	virtual ~Basic() {}
};

class Expanded_0 : public Basic
{
	void method() const override
	{
		std::cout << "Hello from Expanded_0!\n";
	}
};

class Expanded_1 : public Basic
{
	void method() const override
	{
		std::cout << "Hello from Expanded_1!\n";
	}
};

int main()
{
	polymorphic_vector<Basic> vec;

	Expanded_0 temp;
	Expanded_1 temp2;

	vec.push_pack(temp);
	vec.push_pack(temp2);

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->method();
	}
}