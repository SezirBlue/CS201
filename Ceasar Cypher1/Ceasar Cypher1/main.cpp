/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


int getNum();
string getCypher();
char shiftchar(char letter, int shifter);
string Cypher(string message, int USRshiftby);

int main()
{
	while (true)
	{
		string message = getCypher();
		if (message == "")
		{
			return 0;
		}
		int shift = getNum();

		cout << "cyphered message :: \n\n" << Cypher(message, shift) << "\n\n---------------------------------------------"<< endl;
		
	}
	return 0;
}

int getNum()
{
	cout << "enter a number to shift by \n" << endl;
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
			continue;
		}
		break;
	}
	return num;
}

string getCypher()
{
	cout << "enter a message to cypher(press enter to quit): \n" << endl;
	string text;
	getline(cin, text);
	return text;
}

string Cypher(string message, int USRshiftby)
{
	int shiftBy = USRshiftby % 26;
	string newMessage = message;
	for (int i = 0; i<message.size(); ++i)
	{
		newMessage[i] = shiftchar(message[i], shiftBy);
	}

	return newMessage;
}

char shiftchar(char letter, int shifter)
{
	char newchar;
	//letter is lowercase
	if (letter >= 'a' && letter <= 'z')
	{
		newchar = letter + shifter;
		if (newchar < 'a')
		{
			newchar += 26;
		}
		else if (newchar > 'z')
		{
			newchar -= 26;
		}
	}
	//letter is Uppercase
	else if (letter >= 'A' && letter <= 'Z')
	{
		newchar = letter + shifter;
		if (newchar < 'A')
		{
			newchar += 26;
		}
		else if (newchar > 'Z')
		{
			newchar -= 26;
		}
	}
	else
	{
		newchar = letter;
	}
	return newchar;
}