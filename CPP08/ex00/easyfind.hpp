#ifndef EASYFIND_HPP
# define EASYFIND_HPP

class easyfindExeption : public std::exception {
	virtual const char * what() const throw() {return "*can't be found*";}
};

template <typename T>
int easyfind(T &container, int i)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw easyfindExeption();
	return (std::distance(container.begin(), it));
}

#endif