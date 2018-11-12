/*James rine

9.21.18

CS201
boxPrint.cpp
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include "boxer.hpp"




int main()
{
	int size = -1;
	string phrase = "";

	//instructions and example
	cout << "This program  will print a phrase that you give it with a boder made of astritx with the size you indicate." << endl;
	cout << endl << "For example if you input the phrase 'Hello', and the number 4, you will gethe folowing::" << endl << endl;
	
	printBox("Hello", 4);

	cout << "Now it is your turn::" << endl << endl;
	

	//keep running until user indicated to quit by inputting a 0
	while (true)
	{
		size = -1;
		//get integer input for size, with eror check
		while (size < 0)
		{
			cout << "enter a number for the size of the border:: (if you wouldlike to quit, enter 0)" << endl;
			cin >> size;
			if (size < 0)//error check if negitive
				cout << "NUMBER MUST BE POSSITIVE" << endl;
		}

		if (size == 0)
		{
			break;//quit
		}
		//get phrase
		cout << "Now enter a phrase to be featured in the box." << endl;
		cin >> phrase;
		printBox(phrase, size);
	}
	return 0;
}

