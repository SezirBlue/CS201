

#include "lab8.hpp"
#include "intio.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int doInput()
{
	return getInt();
}
int compute(int input)
{
	if (input == 0)
		return 0;
	if (input > 0)
	{
		int out=0;
		for (int i = 1; i < input; ++i)
		{
			if (input % i  == 0)
				++out;
		}
		return out;
	}
}