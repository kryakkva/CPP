#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>

class Array
{
private:
	unsigned int _size;
	T *_array;
public:
	Array() : _size(), _array() { }
	Array(unsigned int n)
	{
		if ((int)n <= 0) {
			if ((int)n < 0)
				throw Array::OverLimitsException();
			_size = 0;
			_array = new T();
		}
		else {
			_size = n;
			_array = new T[n];
		}
	}

	Array(Array const & other) : _size(other._size), _array(new T[other._size]) {
		for (unsigned int i = 0; i < other._size; i++) {
			_array[i] = other._array[i];
		}
	}

	Array &operator= (Array const & other) {
		if (this != &other) {
			delete[] _array;
			_size = other._size;
			_array = new T[other._size];
			for (unsigned int i = 0; i < other._size; i++) {
				_array[i] = other._array[i];
			}
		}
		return *this;
	}

	T &operator[] (unsigned int index)
	{
		if (index >= _size)
			throw Array::OverLimitsException();
		return (_array[index]);
	}

	~Array() { delete[] _array; }

	unsigned int const & size() const { return _size; }

	class OverLimitsException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return ("*overlimit*"); }
	};
};

#endif