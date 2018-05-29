#include <fstream>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <unordered_map>//should be replace to BKDR Hash   // can cmp with hash_map
using namespace std;
typedef vector<string> pstack;

pstack param;//param stack
unordered_map<string, function<void(pstack)>> func_map;

string file_name("astest.s");
ifstream f("./Assembles/astest.s");
string word;

void pp(pstack);
void ppa(pstack);
void ppap(pstack);

//uitil
int toInt(string str);

int main() {
	//vector<string> func_name {"pp", "ppa", "ppap"}
 	func_map["pp"] = pp;
	func_map["ppa"] = ppa;
	func_map["ppap"] = ppap;

	while (f >> word)
	{
		func_map[word](param);
	}

// can c++ use void * to call a function? if func_map is <string, void *>

	return 0;
}

void pp(pstack pst) {
	cout << "pp" << endl;
}

void ppa(pstack pst)
{
	f >> word;
	pst.push_back(word);
	int a = toInt(pst[0]);
	cout << "ppa :" << a << endl;

	pst.pop_back();
}

void ppap(pstack pst) // ori type : fucntion<int(string, int)>
{
	f >> word;
	pst.push_back(word);
	f >> word;
	pst.push_back(word);
	int tmp = toInt(pst[1]);
	cout << "ppap: " << pst[0] << "  " << tmp << endl;

	pst.pop_back();
	pst.pop_back();
}

int toInt(string str) {
	//not safe
	int res = 0;
	for each (auto &var in str)
	{
		if (var != '-')
		{
			res *= 10;
			res += (var - '0');
		}
		else
			res = -res;
	}
	return res;
}