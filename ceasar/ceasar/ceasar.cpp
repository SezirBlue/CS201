/*
James rine

(Date)

CS201
*/

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::istringstream;


//run ceaser cypher
string cShift(string input, int shiftBy);
//shift lowercase letters
char ShiftLowerCase(char shiftCha, int shiftBy);
//shift uppercase letters
char ShiftUpperCase(char shiftCha, int shiftBy);
//get string
string GetCypher();
//get integer
int getNum();



//Start HERE!
int main()
{
	string cypher;
	int shifter;
	while (true)//do until told otherwise
	{
		//get string 
		cout << "Ceasar Chpher::\n\n" << endl;
		cypher = GetCypher();
		if (cypher == "quit")
		{
			break;//told otherwise
		}
		//get number to shift by
		shifter = getNum();
		cout << "Result:: \n\n" << cShift(cypher, shifter) << endl; // print result
	}
	return 0;
}


//get line of input
string GetCypher()
{
	string cypher;
	cout 
		<< "Enter a message to cypher\n"
		<< "enter \"quit\" to exit"
		<< endl;

	getline(cin, cypher);
	return cypher;
}

// run ceasers cipher
string cShift(string shiftStr, int shiftBy)
{
	for (int n = 0; n < shiftStr.size(); ++n) 
	{
		//if lowercase letter
		if ('a' <= shiftStr[n] && shiftStr[n] <= 'z')
		{
			shiftStr[n] = ShiftLowerCase(shiftStr[n], shiftBy);
		}
		//if uppercase letter
		if ('A' <= shiftStr[n] && shiftStr[n] <= 'Z')
		{
			shiftStr[n] = ShiftLowerCase(shiftStr[n], shiftBy);
		}
		//ignore all other values
	}
	return shiftStr;
}

//shift lowercase letters
char ShiftLowerCase(char shiftCha, int shiftBy)
{
	shiftCha = shiftCha + shiftBy;
	if (shiftCha > 'z')//wrap z to a
	{
		shiftCha -= 26;
	}


	return shiftCha;
}

//shift uppercase letters
char ShiftUpperCase(char shiftCha, int shiftBy)
{
	shiftCha = shiftCha + shiftBy;
	if (shiftCha > 'Z')
	{
		shiftCha -= 26;//wrap z to a
	}

	return shiftCha;
}

//get integer input 
int getNum()
{
	cout << "Enter a number to shift by: " << endl;
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