#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T1, typename T2>
void iter (T1 *arr, const T2 &len, void(* funct)(T1 &elem))
{
	if (arr)
	{
		for (T2 i = 0; i < len; i++)
			funct(arr[i]);
	}
}

#endif