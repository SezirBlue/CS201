/*
James rine

10/16/18

CS201
*/


//Program to find GCD of two given numbers
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;


//functions

void printGCD(int a, int b);//prints gcd
int calc(int a, int b);// calculates GCD usiong euclid
int getNum(); //gets integer input with error checking


int main()
{
	cout << "This program is going to ask for two numbers, \nafter two numbers have been entered, \nit will print the GCD of the two. You may enter 0 at any time to quit.\n\n" << endl;

	//repeat the proccess of getting input and finding GCD until user says otherwise
	while (true)
	{
		cout << "enter two positive numbers" << endl;
		int a = getNum();
		if (a == 0)//check for quit
			break;

		int b = getNum();
		if (b == 0)
			break;


		printGCD(a, b);//run euclid
	}
	return 0;
}


//prints the gcd of two given numbers
void printGCD(int a, int b)
{
	int gcd = 0;

	cout << "Th GCD of " << a << " and " << b << " is " << calc(a, b)/*run euclid*/ << "\n" << endl;

}
//euclid function 
int calc(int a, int b)
{

	if (a == 0)
	{
		return b;
	}
	int temp = b % a;
	b = a;
	a = temp;			
	calc(a, b);

}
//gets integer input
int getNum()
{
	string input = "";
	int num = 0;
	while (true)//do until valid input
	{
		cout << "enter a number" << endl;
		getline(cin, input);
		istringstream numValid(input);

		numValid >> num;// put input string into num

		if (!numValid)// input has type conflict
		{
			cout << "input not valid, enter a number" << endl;
		}
		else if (num <0)//negitive input
		{
			cout << "input must be positive" << endl;
		}
		else// good to go
		{
			break;
		}
	}
	return num;
}