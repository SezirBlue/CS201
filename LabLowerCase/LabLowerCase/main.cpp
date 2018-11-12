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

int main()
{
	string in = "";
	while (true)
	{
		in = "";
		cout << "enter a string" << endl;
		cin >> in;
	
		for (int i = 0; i < in.size() ; ++i)
			{
				if (in[i] >= 'a' && in[i] <= 'z')
					cout << in[i] << ",";
			}
		cout << endl;
	} 
	return 0;
}
