#include <iostream>
#include <cstdio>
using namespace std;

int ncoins, btwo, big;
int const COINS = 150;
int bag[COINS], sum, dp[COINS][60000];

int solve(int index, int bone)
{
	if (index == ncoins)
	{
		int btwo = sum - bone;
		return abs(btwo - bone);
	}

	if (dp[index][bone] != -1)
		return dp[index][bone];

	int one = solve(index + 1, bone);
	int two = solve(index + 1, bone + bag[index]);

	return dp[index][bone] = min(one, two);
}

int main()
{
	freopen("in.txt", "rt", stdin);

	int cases;
	scanf("%d", &cases);

	while (cases--)
	{
		sum = 0, scanf("%d", &ncoins);

		for (int i = 0; i < ncoins; ++i)
		{
			scanf("%d", &bag[i]);
			sum += bag[i];
		}

		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(0, 0));
	}
	return 0;
}
