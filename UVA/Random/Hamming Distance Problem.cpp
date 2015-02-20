#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

#define size(A) ((int)A.size())

void BackTrack(string &p_binary, int &p_hamming, int index = 0)
{
	if (index == size(p_binary))
	{
		int sum = 0;
		for (int i = 0; i < size(p_binary); i++) 
		{
			sum += (p_binary[i] - '0');
			if (sum > p_hamming) return;
		}
		if (sum == p_hamming) cout << p_binary << endl;
	}
	else for (int i = 0; i <= 1; i++)
	{
		p_binary[index] = i + '0';
		BackTrack(p_binary, p_hamming, index + 1);
	}
}

int main()
{
	int cases;
	string _binary;
	int length, hamming;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++)
	{
		if (i) cout << endl;
		scanf("%d%d", &length, &hamming);
		_binary.resize(length);
		BackTrack(_binary, hamming);
	}
	return 0;
}