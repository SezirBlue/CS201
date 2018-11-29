/*
James rine

11.17.18

CS201

FindReplace

*** Finds a user inputed string in a text file and 
replaces it with a user inputed sting

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


struct stringWithCount
{
	string line;
	int count;
};

stringWithCount findAndReplace(string find, string replace, string text);
int findInStr(string text, string find);
stringWithCount procesFile(ifstream & fin, string find, string replace);
string getfind();
string getreplace();




int main()
{
	//open file for reading
	ifstream fin("txt.txt");
	if (!fin)
	{
		cout << "Error opening file to read" << endl;//error and close if it doesn't work
		return 1;
	}

	//get user input
	string find = getfind();
	string replace = getreplace();
	

	stringWithCount newText;

	//get the new text file after all the replacements into a string
	newText = procesFile(fin,find,replace);
	

	//open file to write
	ofstream fout("txt.txt");
	if (!fout)
	{
		cout << "Error opening file to write" << endl;//error an close if it doesn't work
	}

	fout << newText.line;//add the new text to the file

	cout << "made " << newText.count << " replacements" << endl;

	return 0;
}

//get text to put into the new file
stringWithCount procesFile(ifstream & fin, string find, string replace)
{
	string text;//old file
	stringWithCount getFromLine;
	getFromLine.line = "";
	getFromLine.count = 0;

	stringWithCount finalText;
	finalText.count = 0;
	finalText.line = "";

	while (getline(fin, text))//go line by line
	{
		getFromLine = findAndReplace(find, replace, text);//add new line
		finalText.line += getFromLine.line;
		finalText.line += "\n";//end line
		finalText.count += getFromLine.count;
	}
	return finalText;//send new text to main
}

//process a line
stringWithCount findAndReplace(string find, string replace, string text)
{
	int progress = 0;//position in old text

	stringWithCount send;//create a string with counter package
	send.line = "";
	send.count = 0;

	int pos = 0;//pos of find

	while (true)//forever loop
	{
		pos = findInStr(text.substr(progress, text.size()-1), find);//find the position of the first instance of find

		//if not found break
		if (pos == -1)
		{
			break;
		}
		
		//add everything up to find to new text
		send.line += text.substr(progress, pos);
		send.line += replace;//add replace
		++send.count;
		progress += pos + find.size();//set position 

	}
	send.line += text.substr(progress);//add the rest

	return send;
}

//find a string
int findInStr(string text, string find)
{
	//go thorugh each letter of string
	for (int pos = 0; pos < text.size(); ++pos)
	{
		if (text.substr(pos, find.size()) == find)//if the string with legth of find is also find
		{
			return pos;//found it
		}
	}

	return -1;//didin't find it
}

//get the find value from user
string getfind()
{
	cout << "enter a query to find" << endl;
	string value;
	getline(cin, value);
	return value;
}
//get the replace value from user
string getreplace()
{
	cout << "enter a value to replace" << endl;
	string value;
	getline(cin, value);
	return value;
}

