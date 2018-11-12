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

int ff(int nn_in, string & ss_out);

int main()
{
	string word = "Hello";

	for (int i = 0; i < ff(6,word); ++i)
	{
		cout << word << endl;
	}
	return 0;
}

int ff(int nn_in, string & ss_out)
{
	string temp = ss_out;
	for (int k = 0; k < nn_in; ++k)
	{
		ss_out += temp;
		return nn_in;
	}
}