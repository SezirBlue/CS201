/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main()
{
	int a = 1;
	for (int c = 1; c < 16; ++c)
	{
		for (int b = 1; b < c; ++b)
		{
			cout << a << " ";
			++a;
		}
		cout << endl;
	}
	return 0;
}