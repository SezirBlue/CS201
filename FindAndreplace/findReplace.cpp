#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::string;


string findRepFile(const string & find, const string & replace, ifstream & fin);
string findRepLine(string  find, string  replace, string  line);
string getFind();
string getReplace();
string getfile();
int main()
{
  string file = getfile();
  string find = getFind();
  string replace = getReplace();



  //open file for reading
  ifstream fin(file);
  if (!fin)
  {
    cout << "couln't open file for reading" << endl;
  }


  string newText = findRepFile(find, replace, fin);

  ofstream fout("txt");
  if (!fout)
  {
    cout << "couldn't open file for writing" << endl;
  }

  fout << newText;
}

string getfile()
{
  string file;
  cout << "enter a file name" << endl;
  getline (cin, file);
  return file;
}

string getFind()
{
  string find;
  cout << "enter a string to find" << endl;
  getline (cin, find);
  return find;
}

string getReplace()
{
  string replace;
  cout << "enter a string to replace" << endl;
  getline (cin, replace);
  return replace;
}


string findRepFile(const string & find, const string & replace, ifstream & fin)
{
  string text;
  string newText;
  while (getline(fin, text))
  {


    cout << text << endl;
    newText += findRepLine(find, replace, text);
    cout << newText << endl;
  }
  return newText;
}

string findRepLine(string  find, string  replace, string  line)
{
  string newText = "";
  int pos;

    while (line.find(find) != line.npos)
    {
    pos = line.find(find);
    newText += line.substr (0,pos);
    line.erase(0,pos+replace.length());
    cout << "**" << line << endl;

    newText += replace;
  }
   newText += line;
   newText += "\n";

   return newText;
}
