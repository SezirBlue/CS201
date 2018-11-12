/*
James rine

(Date)

CS201
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::sort;

int main()
{
	vector<int> data
	{
			21,
			35,
			95,
			17,
			65,
			654,
			-580,
			96,
			895,
			9
	};


	for (auto n : data)
	{
		cout << n << endl;
	}

	sort(begin(data), end(data));
	cout << "\n\n" << endl;

	for (auto n : data)
	{
		cout << n << endl;
	}


	int hold;
	cin >> hold;
	return 0;
}