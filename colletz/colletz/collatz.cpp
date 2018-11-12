/*
James rine

10.21.19

CS201
colletz.cpp
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void c(int n);//prototype

int main()
{
	//declare var
	int input = -1;
	//do until told otherwise
	while (true)
	{
		input = -1;
		//get input with error check
		while (input < 0)
		{
			cout << "enter a possive integer to get its collatz sequence: (enter 0 to quit)" << endl;
			cin >> input;
			if (input < 0)//error check if negitive
				cout << "NUMBER MUST BE POSSITIVE" << endl;
		}
		//check if user wants to quit
		if (input == 0)
			break;//told othewise


		c(input);//run colletz sequence
		cout << endl;// new line

	}


	return 0;
}

void c(int n)//recursive colletz sequence
{
	cout << n << ",";
	if (n == 1)
		return;


	if (!(n % 2))//if n is even

		c(n / 2);
	else// n is odd
		c(3 * n + 1);

	return;
}