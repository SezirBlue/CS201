/*
James Rine
9/2/18

factor an int
*/

#include <iostream> // we need this
#include <math.h>

using std::cout;
using std::endl;
using std::cin;


void factor(int in)//uses long long to allow factoring of really big numbers
// takes an input and test every value from 1 to half the value and prints it only if it is a factor of the input
{
	while (in % 2 == 0)
	{
		in /= 2;
		cout << "2" << "   ";
	}
	for (int i = 3; i <= in; ++i) 
	{
		if (in % i == 0) //condition, if the is no remainder after dividing, than you have found a factor.
		{
			while (in%i == 0)
			{
				in /= i;
				cout << (i) << "  ";//print factor
			}
		}
	}
}

bool isPrime(int n);

int main()//start here
{
	int input = 0; //get input from user and assign to variable
	cout << "Enter in to factor:" << endl;
	cin >> input;

	
	factor(input);//run funtion (void factor(int in)); on user input

	if (isPrime(input))
	{
		cout << "is prime" << endl;
	}
	return 0;//end here
}

bool isPrime(int n)
{
	for (int i = 2; i < n / 2 + 1; ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}