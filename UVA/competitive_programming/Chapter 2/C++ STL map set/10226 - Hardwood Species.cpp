#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

#define SIZE(a) ((int)a.size())

int main()
{
	int test_cases; scanf("%d", &test_cases);
	cin.ignore();
	string str; getline(cin, str);
	for (bool first = true; test_cases--; first = false)
	{
		if (!first) puts("");
		map<string, int> data;
		int all = 0;
		for (string s; getline(cin, s) && s != "";) data[s]++, ++all;
		for (map<string, int>::iterator it = data.begin(); it != data.end(); it++)
			printf("%s %.4lf\n", it->first.c_str(), (it->second * 100.) / all);
	}
	return 0;
}