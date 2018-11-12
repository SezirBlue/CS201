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


//struct for key value pairs
struct KD
{
	int k;
	int d;
};

//Prints entire dataset (for testing)
void printAssoc(vector <int> & data);
//adds input to data at specified key
void addKeyData(int k, int d, vector <KD> & data);
//prints the option menu
void printMenu();
//get input from user for menu opt
int getMenuOpt();
// run option one
void menu1(vector <KD> & data);
//run option 2
void menu2(vector <KD> & data);
//get integer input from user
int getNum();

int sequentialSearch(const vector<KD> & data, int find);




int main()
{
	//initialization
	vector < KD> data;
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
			continue;
		}
		break;
	}
	return num;
}




//prints dataset for testing
void printAssoc(vector <KD> & data)
{

	for (const auto p : data)
	{
		cout << p.k << "     " << p.d << endl;
	}
}
//adds a key value pair to data
void addKeyData(int k, int d, vector <KD> & data)
{
	KD temp;
	temp.k = k;
	temp.d = d;
	data.push_back(temp);
}


//adds specified value at specified key
void menu1(vector <KD> & data)
{
	cout << "What is the data you would like to add?" << endl;
	int tempData = getNum();

	cout << "What key would you like to add it as?" << endl;
	int tempKey;
	//check number possitive
	while (true)
	{
		tempKey = getNum();
		if (tempData > 0)
		{
			break;
		}
		cout << "Key must be possitive" << endl;
	}
	//add data and key
	addKeyData(tempKey, tempData, data);
}

//reads data at specified key
void menu2(vector <KD> & data)
{
	if (data.size() == 0)
	{
		cout << "Dataset must have content before reading." << endl;
		return;
	}
	cout << "What is the key you would like to read?" << endl;
	int readKey;
	while (true)
	{
		readKey = getNum();
		if (readKey <= 0)
		{
			cout << "Key must be possitive" << endl;
			continue;
		}
		break;
	}
	int found = sequentialSearch(data, readKey);
	if (found == -1)
	{
		cout << "key not in dataset" << endl;
	}
	cout << "key found, the Data for key " << readKey << " is " << found << endl << endl;
}

//search the dataset
int sequentialSearch(const vector<KD> & data, int find)
{
	for (auto n : data)
	{
		if (find == n.k)
		{
			return n.d;
		}
	}
	return -1;
}