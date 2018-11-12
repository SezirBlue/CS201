// truncstruct.h
// Glenn G. Chappell
// 19 Mar 2018
//
// For CS 201 Spring 2018
// Header for functions trunc8, trunc
// struct version
//
// Modified 10/24/18
// Chris Hartman
// For CS 201 Fall 2018

#ifndef FILE_TRUNCSTRUCT_HPP_INCLUDED
#define FILE_TRUNCSTRUCT_HPP_INCLUDED

#include <string>

// struct SI
// Holds string and info about its length.
struct SI {
	std::string str;
	int         len;
};

// trunc
// Given struct SI, truncates given string to length at most given
// length (or 0 if this is negative) and converted to upper-case.
// Returns new struct SI of resulting string and its length.
SI trunc(const SI & t);

// trunc8
// Given a string, truncates input string to length at most 8 and
// converted to upper-case. Returns struct SI holding resulting string
// and its/ length.
SI trunc8(const std::string & s);

#endif //#ifndef FILE_TRUNCSTRUCT_HPP_INCLUDED

