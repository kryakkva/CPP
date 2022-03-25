#include "Span.hpp"

Span::Span(unsigned int n) : _size(n) {}
Span::~Span() {}

Span::Span(Span const &other)
{
	_size = other._size;
	_arr = other._arr;
}

Span & Span::operator= (Span const &other)
{
	if (this != &other)
	{
		_size = other._size;
		_arr = other._arr;
	}
	return *this;
}

int &Span::operator[] (int i)
{
	if ((unsigned int)i >= _arr.size())
		throw Span::SpanExeption("*Wrong index, over limit*");
	return (_arr[i]);
}

void Span::addNumber(int num)
{
	if (_arr.size() >= _size)
		throw Span::SpanExeption("*store is full*");
	_arr.push_back(num);
}

int Span::longestSpan()
{
	if (_arr.size() < 2)
		throw Span::SpanExeption("*no span can be found*");

	int min;
	std::vector<int>::iterator it;
	it = min_element(_arr.begin(), _arr.end());
	min = *it;
	it = max_element(_arr.begin(), _arr.end());
	return *it - min;
}

int Span::shortestSpan()
{
	if (_arr.size() < 2)
		throw Span::SpanExeption("*no span can be found*");

	std::vector<int> tmp;
	std::vector<int>::iterator it;
	int i = -1;
	int dif = INT_MAX;

	tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	for (it = tmp.begin(); it != tmp.end(); it++)
	{
		if (i != -1 && dif > *it - i)
			dif = *it - i;
		i = *it;
	}
	
	return dif;
}