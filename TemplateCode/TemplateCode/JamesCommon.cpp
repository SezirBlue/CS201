/*
James rine

(Date)

CS201
*/

#include "JamesCommon.hpp"

#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::istringstream;

int getNum(string prompt)
{

	string textin;
	int num;


	istringstream numValid(textin);

	while (true)
	{
		cout << prompt << endl;
		getline(cin, textin);

		istringstream numValid(textin);
		numValid >> num;
		
		if (numValid)
		{
			break;
		}
		cout << "Input invalid" << endl;
	}

	return num;

}

int getNumPos(string prompt)
{

	string textin;
	int num;


	istringstream numValid(textin);

	while (true)
	{
		cout << prompt << endl;
		getline(cin, textin);

		istringstream numValid(textin);
		numValid >> num;
		if (!numValid)
		{
			cout << "Input invalid" << endl;
			continue;
		}
		if (num < 0)
		{
			cout << "Number must be positive" << endl;
			continue;

		}
			break;
	}

	return num;

}


string getText(string prompt)
{
	string output;
	cout << prompt << endl;

	getline(cin, output);

	return output;
}