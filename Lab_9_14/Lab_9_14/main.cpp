/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "intio.hpp"



int main()
{
	int input = 1;
	int sum = 0;
	while (input != 0)
	{
		cout << "enter an integer, i will add them together." << endl;
		input << getInt();
		sum += input;
	}
	cout << sum << endl;
	return 0;
}