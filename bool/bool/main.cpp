/*
James rine

9.21.18

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

bool isDiv3(int input)
{
	return !(input % 3);
}

int main()
{
	cout << "the following is a list of all multiples of 3 from 1 to 40" << endl;
	for (int i = 0; i <= 40; ++i)
	{
		if (isDiv3(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}

