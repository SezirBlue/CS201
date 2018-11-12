/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <random>
using std::mt19937;
using std::random_device;
random_device rd;
mt19937 rnJesus(rd());
std::uniform_int_distribution<int> coin(0, 1);


int main()
{
	if (coin(rnJesus))
	{
		cout << "breakfast";
		return 0;
	}
	cout << "lunch";
	return 0;
}