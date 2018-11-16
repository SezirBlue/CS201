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
using std::ifstream;
#include <ostream>
using std::ofstream;
#include<string>
using std::string;
using std::getline;



string findAndReplace(string find, string replace, string text);
int findInStr(string text, string find);



int main()
{
	ifstream fin("txt.txt");
	if (!fin)
	{
		cout << "Error opening file to read" << endl;
		return 1;
	}
	ofstream fout("txt.txt");
	if (!fout)
	{
		cout << "Error opening file to write" << endl;
		return 1;
	}

	string find = "find";
	string replace = "replace";
	
	string test;
	fin >> test;
	cout << test;
	

	
	return 0;
}


string procesFile(ifstream & fin, string find, string replace)
{
	string text;
	string newText = "";
	while (getline(fin, text))
	{
		newText += findAndReplace(find, replace, text);
	}
	return newText;
}


string findAndReplace(string find, string replace, string text)
{
	string newText = "";
	int progress = 0;

	int pos = 0;
	while (true)
	{
		pos = findInStr(text.substr(progress, text.size()-1), find);

		if (pos == -1)
		{
			break;
		}

		newText += text.substr(progress, pos);
		newText += replace;

		progress += pos + find.size();

	}
	newText += text.substr(progress);

	return newText;
}


int findInStr(string text, string find)
{

	for (int pos = 0; pos < text.size(); ++pos)
	{
		if (text.substr(pos, find.size()) == find)
		{
			return pos;
		}
	}

	return -1;
}


