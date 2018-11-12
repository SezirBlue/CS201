/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include<vector>
using std::vector;
#include <algorithm>
using std::mismatch;
using std::find_if;



void findDiv5(vector<int> vec)
{
	auto itter1 = find_if(begin(vec), end(vec), [](auto a) { return !(a % 5); });//find multiple of five



	if (itter1 == end(vec))
	{
		cout << "no multiple of five found" << endl;
	}
	else
	{
		cout << "Multiple of five found:: " << *itter1 << endl;
	}
}


int main()
{
	vector <int> vec1{
		1,
		2,
		3,
		15,
		4,
		5,
		6,
		7,
		8,
		9,
	};

	vector <int> vec2{
	1,
	2,
	3,
	4,
	6,
	7,
	8,
	9,
	};

	findDiv5(vec1);
	cout << endl;
	findDiv5(vec2);

	
	return 0;
}