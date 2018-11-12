// truncstruct.cpp
// Glenn G. Chappell
// 19 Nov 2018
//
// For CS 201 Spring 2018
// Source for functions trunc8, trunc
// struct version
//
// Modified 10/24/18
// Chris Hartman
// For CS 201 Fall 2018

#include "truncstruct.hpp"
// For struct SI definition
#include <string>
using std::string;
#include <cctype>
using std::toupper;


// trunc
// (See header for description.)
SI trunc(const SI & t)
{
	// Get input string & maxlen
	string s = t.str;
	int maxlen = t.len;
	if (maxlen < 0)
		maxlen = 0;

	// Truncate string & get its new length
	if (int(s.size()) > maxlen)
		s = s.substr(0, maxlen);
	int len = int(s.size());

	// Convert string to upper-case
	for (int i = 0; i < len; ++i)
		s[i] = char(toupper(s[i]));

	// Create return value
	return SI{ s, len };
}

// trunc8
// (See header for description.)
SI trunc8(const string & s)
{
	return trunc(SI{ s, 8 });
}
