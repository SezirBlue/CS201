/*James rine

9.21.18

CS201
boxer.cpp
*/
#include "boxer.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;



//this function is the puts together smaller pieces to print the box, with the phrase nested inside.
void printBox(string print, int size)
{
	int width = print.size() + 1 + (size * 2);
	printBuffer(width, size);

	printEdge(size);
	printSpace(print);
	printEdge(size);
	cout << endl;

	printEdge(size);
	cout << " " << print << " ";
	printEdge(size);
	cout << endl;

	printEdge(size);
	printSpace(print);
	printEdge(size);
	cout << endl;

	printBuffer(width, size);


	return;
}


//prints the top portion of the box, with as many rows and columns as nessessary.
void printBuffer(int width, int buffer)
{
	for (int i = 0; i <= buffer-1; ++i)
	{
		for (int k = 0; k <= width; ++k)
		{
			cout << "*";
		}
		cout << endl;
	}
	return;
}

//prints the boder next to the phrase
void printEdge(int size)
{
	for (int i = 0; i <= size-1; ++i)
	{
		cout << "*";
	}
}

//puts space above and bellow the phrase to allow it to be easier read.
void printSpace(string phrase)
{
	for (int i = 0; i <= phrase.size() + 1; ++i)
	{
		cout << " ";
	}
}
