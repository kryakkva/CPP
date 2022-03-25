#include <iostream>

class Base { public: virtual ~Base(){} };
class A : public Base { public: virtual ~A(){} };
class B : public Base { public: virtual ~B(){} };
class C : public Base { public: virtual ~C(){} };

enum {a, b, c};

Base * generate(void)
{
	int num = rand() % 3;
	switch (num)
	{
	case a:
		return new A;
	case b:
		return new B;
	case c:
		return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown class" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::bad_cast)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::bad_cast)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::bad_cast)
			{
				std::cout << "unknown class" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base *base;

	for (size_t i = 0; i < 10; i++)
	{
		base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	
	return 0;
}