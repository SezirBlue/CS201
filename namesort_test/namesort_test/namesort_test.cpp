// namesort_test.cpp
// VERSION 2
// Glenn G. Chappell
// 30 Mar 2018
// Updated: 4 Apr 2018
//
// For CS 201 Spring 2018
// Test Program for nameSort
// Used in Assignment 4, Exercise B
//
// Updated 11/5/18
// by Chris Hartman
// for CS 201 Fall 2018

#include "namesort.hpp"  // For nameSort
#include "namesort.hpp"  // Double inclusion test
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <algorithm>
using std::equal;
#include <iterator>
using std::begin;
using std::end;
#include <string>
using std::pair;
using std::string;




// printVec
// Print vector of pair<string, string>, all on one line, preceded by 6
// blanks, with newline at end.
void printVec(const vector<pair<string, string>> & v)
{
	cout << "      { ";
	bool first = true;
	for (const auto p : v)
	{
		if (first)
		{
			first = false;
		}
		else
		{
			cout << ", ";
		}
		cout << "{\"" << p.first << "\", \"" << p.second << "\"}";
	}
	cout << " }" << endl;
}


// test
// Do single test of function nameSort. "start" is vector to pass.
// "correct" is expected result. "msg" is name of test. Results are
// printed. If test fails, then allgood is set to false.
void test(bool & allgood,
	const vector<pair<string, string>> & start,
	const vector<pair<string, string>> & correct,
	const string & msg)
{
	cout << "  " << msg << " - ";
	auto data = start;
	nameSort(data);
	if (data.size() == correct.size()
		&& equal(begin(data), end(data), begin(correct)))
	{
		cout << "passed" << endl;
	}
	else
	{
		allgood = false;
		cout << "FAILED ******************" << endl;
		cout << "    initial data:" << endl;
		printVec(start);
		cout << "    expected result:" << endl;
		printVec(correct);
		cout << "    actual result:" << endl;
		printVec(data);
	}
}


// test_nameSort
// Test suite for function nameSort. Returns true if all tests pass;
// false otherwise.
bool test_nameSort()
{
	cout << "Test Suite for nameSort" << endl;
	bool allgood = true;

	{
		vector<pair<string, string>> s{};
		vector<pair<string, string>> c{};
		test(allgood, s, c, "empty vector");
	}

	{
		vector<pair<string, string>> s{ {"a","b"} };
		vector<pair<string, string>> c{ {"a","b"} };
		test(allgood, s, c, "size 1 vector");
	}

	{
		vector<pair<string, string>> s{ {"c","a"},{"b","d"} };
		vector<pair<string, string>> c{ {"c","a"},{"b","d"} };
		test(allgood, s, c, "size 2 vector, #1");
	}

	{
		vector<pair<string, string>> s{ {"b","d"},{"c","a"} };
		vector<pair<string, string>> c{ {"c","a"},{"b","d"} };
		test(allgood, s, c, "size 2 vector, #2");
	}

	{
		vector<pair<string, string>> s{ {"a","b"},{"d","b"} };
		vector<pair<string, string>> c{ {"a","b"},{"d","b"} };
		test(allgood, s, c, "size 2 vector, #3");
	}

	{
		vector<pair<string, string>> s{ {"d","b"},{"a","b"} };
		vector<pair<string, string>> c{ {"d","b"},{"a","b"} };
		test(allgood, s, c, "size 2 vector, #4");
	}

	{
		vector<pair<string, string>> s{
			{"d","b"},{"c","a"},{"a","d"},{"b","b"}
		};
		vector<pair<string, string>> c{
			{"c","a"},{"d","b"},{"b","b"},{"a","d"}
		};
		test(allgood, s, c, "size 4 vector");
	}

	{
		vector<pair<string, string>> s{
			{"c","b"},{"a","a"},{"x","c"},{"a","c"},
			{"x","d"},{"a","c"},{"a","d"},{"m","c"},
			{"b","a"},{"f","c"},{"b","d"},{"h","c"}
		};
		vector<pair<string, string>> c{
			{"a","a"},{"b","a"},{"c","b"},{"x","c"},
			{"a","c"},{"a","c"},{"m","c"},{"f","c"},
			{"h","c"},{"x","d"},{"a","d"},{"b","d"}
		};
		test(allgood, s, c, "size 12 vector");
	}

	return allgood;
}


// Main program
// Run tests for function nameSort. Print results.
int main()
{
	bool success = test_nameSort();
	cout << endl;

	if (success)
	{
		cout << "All tests passed" << endl;
	}
	else
	{
		cout << "NOT ALL TESTS PASSED" << endl;
	}
	cout << endl;

	cout << "Press ENTER to quit ";
	while (cin.get() != '\n');
}
