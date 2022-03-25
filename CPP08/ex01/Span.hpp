#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <iterator>
# include <algorithm> 


class Span
{
private:
	unsigned int _size;
	std::vector<int> _arr;
public:
	Span(unsigned int n);
	Span(Span const &other);
	Span &operator= (Span const &pther);
	int &operator[] (int i);
	~Span();

	void addNumber(int num);
	template <typename T>
	void addNumber(T begin, T end)
	{
		if (std::distance(begin, end) > _size)
			throw Span::SpanExeption("*Out of range*");
		for (; begin != end; begin++)
			_arr.push_back(*begin);
	}

	int shortestSpan();
	int longestSpan();
	
	int getSize() {return _size;}
	int getFSize() {return _arr.size();}

	class SpanExeption : public std::exception
	{
	private:
		const std::string _err;
	public:
		SpanExeption(std::string err) : _err(err) {};
		virtual ~SpanExeption() throw() {};
		virtual const char *what() const throw() { return _err.c_str();}
	};
};

#endif