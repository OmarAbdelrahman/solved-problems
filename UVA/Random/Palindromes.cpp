#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define Size(A) ((int)A.size())
bool CheckPalindrome(string);
bool CheckMirroredString(string);

int main()
{
	string word;

	while (cin >> word)
	{
		bool palindrome = CheckPalindrome(word);
		bool mirroredStr = CheckMirroredString(word);

		if (palindrome && mirroredStr)
		{
			cout << word << " -- is a mirrored palindrome." <<endl << endl;
		}
		else if (palindrome)
		{
			cout << word << " -- is a regular palindrome." << endl << endl;
		}
		else if (mirroredStr)
		{
			cout << word << " -- is a mirrored string." << endl << endl;
		}
		else
		{
			cout << word << " -- is not a palindrome." << endl << endl;
		}
	}

	return 0;
}

bool CheckPalindrome(string p_word)
{
	string temp = p_word;
	reverse(p_word.begin(), p_word.end());

	if (temp == p_word)
		return true;
	else return false;
}

bool CheckMirroredString(string p_word)
{
	for (int i = 0, j = Size(p_word); i < j; i++, j--)
	{
		if (!i) j--;
		switch (p_word[i])
		{
		case 'A':
			if (p_word[j] == 'A') continue;
			else return false;
			break;

		case 'E':
			if (p_word[j] == '3') continue;
			else return false;
			break;

		case 'H':
			if (p_word[j] == 'H') continue;
			else return false;
			break;

		case 'I':
			if (p_word[j] == 'I') continue;
			else return false;
			break;

		case 'M':
			if (p_word[j] == 'M') continue;
			else return false;
			break;

		case 'O':
			if (p_word[j] == 'O') continue;
			else return false;
			break;

		case 'T':
			if (p_word[j] == 'T') continue;
			else return false;
			break;

		case 'U':
			if (p_word[j] == 'U') continue;
			else return false;
			break;

		case 'V':
			if (p_word[j] == 'V') continue;
			else return false;
			break;

		case 'W':
			if (p_word[j] == 'W') continue;
			else return false;
			break;

		case 'X':
			if (p_word[j] == 'X') continue;
			else return false;
			break;

		case 'Y':
			if (p_word[j] == 'Y') continue;
			else return false;
			break;

		case '1':
			if (p_word[j] == '1') continue;
			else return false;
			break;

		case '8':
			if (p_word[j] == '8') continue;
			else return false;
			break;

		case 'J':
			if (p_word[j] == 'L') continue;
			else return false;
			break;

		case 'L':
			if (p_word[j] == 'J') continue;
			else return false;
			break;

		case 'S':
			if (p_word[j] == '2') continue;
			else return false;
			break;

		case 'Z':
			if (p_word[j] == '5') continue;
			else return false;
			break;

		case '2':
			if (p_word[j] == 'S') continue;
			else return false;
			break;

		case '3':
			if (p_word[j] == 'E') continue;
			else return false;
			break;

		case '5':
			if (p_word[j] == 'Z') continue;
			else return false;
			break;

		default: return false;
		}
	}
	return true;
}