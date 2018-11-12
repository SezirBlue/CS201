// readfile.cpp  INCOMPLETE
// Glenn G. Chappell
// 6 Apr 2018
//
// For CS 201 Spring 2018
// Write & read a text file
//
// Updated 11/11/18
// Chris Hartman
// For CS 201 Fall 2018

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;


// Set the following to true to create formatting errors in the file.
const bool MAKE_FILE_ERRORS = false;


// readFile
// Given the filename of a file, read this file, assuming one integer
// per line, and print these integers to the standard output. Returns
// true on success, false on error.
bool readFile(const string & filename)
{
    // Write this!!!
    ifstream fin(filename);
    if (!fin)
    {
		cout << "error opening file to write" << endl;
	}

    while (true)
    {
		string line;
		int num;
		getline(fin, line);
		istringstream isNum(line);
		isNum >> num;
		
		if (!isNum)
		{
			return false;
		}
		else
		{
			cout << num << endl;
		}
		
		if (!fin)
		{
			break
		}
		
	}
	
    
    
    return true;  // DUMMY return
}


// writeFile
// Write data to file with given filename. If MAKE_FILE_ERRORS is false,
// writes one integer per line. Otherwise, writes something else.
// Returns true on success, false on I/O error.
bool writeFile(const string & filename)
{
    random_device rd;
    mt19937 gen(rd());  // PRNG, randomly seeded

    // Open file
    ofstream fout(filename);
    if (!fout)
        return false;

    // Figure line count
    uniform_int_distribution<int> dist1(12, 20);
    int numlines = dist1(gen);

    // Print file contents
    uniform_int_distribution<int> dist2(1, 100);
    for (int i = 0; i < numlines; ++i)
    {
        if (i == 8 && MAKE_FILE_ERRORS)
        {
            fout << "qwerty 30" << endl;
            if (!fout)
                return false;
        }
        else
        {
            fout << dist2(gen) << endl;
            if (!fout)
                return false;
        }
    }
    fout << 200+dist2(gen);
    if (!fout)
        return false;

    // Done
    return true;
}


// Main program
// Call writeFile, then readFile, printing appropriate error messsages.
int main()
{
    const string fname = "data_11_11.txt";  // File to write & read

    // Write
    cout << "Creating file" << endl;
    bool writesuccess = writeFile(fname);
    if (!writesuccess)
    {
        cout << "********** ERROR writing file; exiting" << endl;
        cout << endl;
    }
    else
    {
        cout << "File successfully written" << endl;
        cout << endl;

        // Read
        cout << "Reading file" << endl;
        cout << endl;

        bool readsuccess = readFile(fname);
        cout << endl;

        if (!readsuccess)
        {
            cout << "********** ERROR reading file" << endl;
            cout << endl;
        }
    }

    // Wait for user
    cout << "Press ENTER to quit ";
    string dummyline;
    getline(cin, dummyline);
}

