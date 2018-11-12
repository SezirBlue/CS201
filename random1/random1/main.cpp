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
using std::uniform_int_distribution;

uniform_int_distribution<int> coin(0, 1);

bool flipcoin(mt19937 & generator)
{
	

	int flip = coin(generator);
	return flip;
}

int main()
{
	mt19937 random(std::random_device{}());
	int heads = 0;
	int tails = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (flipcoin(random))
		{
			cout << "heads" << endl;
			++heads;
		}
		else
		{
			cout << "tails" << endl;
			++tails;
		}



	}
	cout << "number of heads:: " << heads << endl
		<< "number of tails:: " << tails << endl;
	return 0;
}

