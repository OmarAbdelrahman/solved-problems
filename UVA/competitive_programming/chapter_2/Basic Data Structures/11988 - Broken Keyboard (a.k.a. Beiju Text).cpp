#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
using namespace std;

#define foreach(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int main(int argc, char **argv)
{
	for (string sent; getline(cin, sent);)
	{
		list<char> v;
		list<char>::iterator it = v.begin();
		foreach(ch, sent)
		{
			if (*ch != '[' && *ch != ']')
				v.insert(it, *ch);
			else if (*ch == '[')
				it = v.begin();
			else
				it = v.end();
		}
		foreach(character, v) cout << *character;
		cout << endl;
	}
	return 0;
}
