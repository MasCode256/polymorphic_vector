#include <stdexcept>
#include <iostream>
#include <vector>
#include <memory>

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
	try
	{
		std::vector<std::unique_ptr<Basic>> vec;

		std::unique_ptr<Basic> temp = std::make_unique<Expanded_0>();
		vec.push_back(std::move(temp));

		vec.push_back(std::make_unique<Expanded_1>());

		for (const auto &i : vec)
		{
			i->method();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error:" << e.what() << '\n';
	}
}