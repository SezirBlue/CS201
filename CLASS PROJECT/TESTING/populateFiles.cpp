/*

James Rine

this program uses the master file to populate the test files;
*/
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <ostream>
using std::ofstream;
#include <string>
using std::string;
using std::getline;


int main()
{
    //open master
    ifstream fin("MASTER");
	if (!fin)
	{
		cout << "Error opening file to read" << endl;//error and close if it doesn't work
		return 1;
	}
    //open each test file
    ofstream fout1("test1");
    if (!fout1)
    {
        cout << "error opening file 1 to write" << endl;
    }
    ofstream fout2("test2");
    if (!fout1)
    {
        cout << "error opening file 2 to write" << endl;
    }
        ofstream fout3("test3");
    if (!fout1)
    {
        cout << "error opening file 3 to write" << endl;
    }
    //get line from master into each test file
    string move;
    getline(fin, move);
    fout1 << move;
    getline(fin, move);
    fout2 << move;
    getline(fin, move);
    fout3 << move;

    return 0;
}