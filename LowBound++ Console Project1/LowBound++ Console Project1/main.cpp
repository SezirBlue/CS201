/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
using std::lower_bound;
#include <algorithm>
using std::sort;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include<string>
using std::string;
#include <sstream>
using std::istringstream;


random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> distro(6, 8);
uniform_int_distribution<int> distro1(1, 4);


void fillVec(vector<int> & data);
void sortVec(vector<int> & data);
void printVec(const vector<int> & data);
int getNum();
void printIntro();

int main()
{
	//print desctiption
	printIntro();
	//create vector and make big and sorted
	vector <int> vec;
	fillVec(vec);
	sortVec(vec);


	//get num to seatch
	int find = getNum();

	//get lower bound
	vector<int>::iterator low;
	low = lower_bound(begin(vec), end(vec), find);

	if (low == end(vec))//check if it is at the end
	{
		cout << find << "not found in dataset," << find << " is greater than al' entries" << endl;
		return 0;
	}

	if (*low == find)//check if not found
	{

		cout << find << " found, the lowest place where found is located is " << (low - begin(vec));
		return 0;
	}
	//if found
	cout << find << " not found, the lowest place in the vector where " << find << " can be inserted is " << (low - begin(vec));
	
	return 0;
}

//fills the vector with random numbers
void fillVec(vector<int> & data)
{
	cout << "creating a vector of random numbers between 0 and 9::" << endl;

	for (int i = 0; i < 50; ++i)
	{
		//potentially fill with any digt but 5, 0, 9
		data.push_back(distro(rng));
		data.push_back(distro1(rng));
	}
	cout << "DONE:: vector created with size " << data.size() << " \n" << endl;
}

//sorts the vector
void sortVec(vector<int> & data)
{
	cout << "sorting vector::" << endl;
	sort(begin(data), end(data));
	cout << "DONE:: \n" << endl;

}

//prints the contents for testing
void printVec(const vector<int> & data)
{
	for (auto n : data)
	{
		cout << n << endl;
	}
}
//get integer input between 0 and 9
int getNum()
{
	{
		cout << "enter a digit (0-9) to search for in the vector::" << endl;
		string input = "";
		int num = 11;
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
			if (!(num >= 0 && num <= 9))
			{
				cout << "input invalid, must be a digit (0-9)" << endl;
				continue;
			}
			break;
		}
		return num;
	}

}
//print instructions and a border thinggy
void printIntro()
{
	cout << "This program creates a vector that is filled with random digits. \n\n"
		<< "0, 5, and 9 are each omited from the vector and should not exist.\n\n"
		<< "The program will ask for a digit from 0-9 and use it to find the lower bound of your input.\n\n"
		<< "Lower bound of 0 should always return not found 0, 5 should retun not found around 50ish, \n"
		"and 9 should return not found and larger than all items in dataset. any other digit should be found (unless the rng really didn't want it).\n\n" << endl;

	for (int i = 0; i < 50; ++i)
	{
		cout << "*";
	}
	cout << "\n\n\n" << endl;
}