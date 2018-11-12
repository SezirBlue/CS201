#include <vector>
#include <string>
using std::vector;
using std::pair;
using std::string;
#include <algorithm>
using std::stable_sort;



void nameSort(std::vector<std::pair<std::string, std::string>> & vec)
{
	//stablesort
	stable_sort(begin(vec), end(vec), [](pair<string, string> a, pair<string,string> b) 
	{
		return (a.second < b.second);
	});
}