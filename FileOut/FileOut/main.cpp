/*
James rine

(Date)

CS201
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <fstream>
using std::ofstream;


int main()
{
	ofstream fout("file.txt");
	if (!fout)
	{
		cout << "problem opening file" << endl;
		return 1;
	}

	fout << "hey" << endl;

	if (!fout)
	{
		cout << "problem writing to file" << endl;
		return 2;
	}

	return 0;
}