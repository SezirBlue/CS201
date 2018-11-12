/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "truncstruct.hpp"
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


string getPhrase();
int getNum();

int main()
{
	string s1 = getPhrase();
	int num1 = getNum();

	SI si1;

	si1.str = s1;
	si1.len = num1;

	SI si2 = trunc(si1);

	cout << si2.str << si2.len << endl;
	return 0;
}

string getPhrase()
{
	string phrase;
	cout
		<< "Enter a message"
		<< endl;


	getline(cin, phrase);
	return phrase;
}

int getNum()
{
	cout << "Enter a number" << endl;
	string input = "";
	int num = 0;
	while (true)//do until valid input
	{

		getline(cin, input);
		istringstream numValid(input);

		numValid >> num;// put input string into num

		if (!numValid)// input has type conflict
		{
			cout << "input not valid, enter a number" << endl;
		}
		else // good to go
		{
			break;
		}
	}
	return num;
}