/*
James rine

10/17/1

CS201
*/


/*
This program created two datasets, one for keys, and one for data,
it allows the user to add data to specified keys and read data from specified keys

*/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <map>
using std::map;

//adds input to data at specified key
void addKeyData(int k, int d,   map<int,int> & data);
//prints the option menu
void printMenu();
//get input from user for menu opt
int getMenuOpt();
// run option one
void menu1(  map<int,int> & data);
//run option 2
void menu2(  map<int,int> & data);
//get integer input from user
int getNum();

int main()
{
	//initialization
	map<int, int> data;
	int menuOpt = 0;
	//do until otherwise noted
	while (!(menuOpt == 3))
	{
		printMenu();

		//get input and run a menu option
		menuOpt = getMenuOpt();
		switch (menuOpt)
		{
		case 1: //option 1
			menu1(data);
			break;
		case 2: // option 2
			menu2(data);
			break;
		case 3: //note otherwise
			cout << "Thanks, BYE!!" << endl;
			break;
		default:
			break;
		};

	}


	return 0;
}

//print menu
void printMenu()
{
	cout << "Associative dataset:: \n"
		<< "\n To set the value with a key, press 1"
		<< "\n To veiw the value associated with a key, press 2"
		<< "\n To quit, press 3" << endl;
}


//get menu option 
int getMenuOpt()
{
	int opt;
	//check that number is 1, 2, or 3
	while (true)
	{
		opt = getNum();
		if ((1 <= opt && opt <= 3))
		{
			break;
		}
		cout << "input must be 1, 2, or 3" << endl;
	}
	return opt;//return selected value
}



//get input integer with error checking
int getNum()
{
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



//add a key value pair to dataset
void addKeyData(int k, int d, map<int, int> & data)
{
	data[k] = d;
}


//run menu option 1, get input to add to dataset
void menu1( map<int,int> & data)
{
	cout << "What is the data you would like to add?" << endl;
	int tempData = getNum();

	cout << "What key would you like to add it as?" << endl;
	int tempKey;
	//check number possitive
	while (true)
	{
		tempKey = getNum();
		if (tempKey > 0)
		{
			break;
		}
		cout << "Key must be possitive" << endl;
	}
	//add data and key
	addKeyData(tempKey, tempData, data);
}

//read value at specified key
void menu2( map<int,int> & data)
{
	//if empty dont do
	if (data.size() == 0)
	{
		cout << "Dataset must have content before reading." << endl;
		return;
	}
	cout << "What is the key you would like to read?" << endl;
	int readKey;
	//get user input for key
	while (true)
	{
		readKey = getNum();
		if (readKey < 0)
		{
			cout << "Key must be possitive" << endl;
			continue;
		}
		break;
	}
	//if not in dataset
	if (data.count(readKey)== 0)
	{
		cout << "key not in dataset" << endl;
	}
	//is in dataset
	else
	{
		cout << "key found, the Data for key " << readKey << " is " << data[readKey] << endl << endl;
	}
}


