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
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

//Prints entire dataset (for testing)
void printAssoc(vector <int> & keys, vector <int> & data);
//adds input to data at specified key
void addKeyData(int k, int d, vector <int> & keys, vector <int> & data);
//prints the option menu
void printMenu();
//get input from user for menu opt
int getMenuOpt();
// run option one
void menu1(vector <int> & keys, vector <int> & data);
//run option 2
void menu2(vector <int> & keys, vector <int> & data);
//get integer input from user
int getNum();
int sequentialSearch(const vector<int> & data, int find);

int main()
{
	//initialization
	vector <int> keys;
	vector <int> data;
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
			menu1(keys, data);
			break;
		case 2: // option 2
			menu2(keys, data);
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
	cout<< "Associative dataset:: \n"
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
	return opt;
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
