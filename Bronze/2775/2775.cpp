// <https://www.acmicpc.net/problem/2775>
// 2775번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int apartment[20][20];

signed main()
{
	fastio;
	int test_cnt, floor, room;

	for (int i = 1; i < 15; ++i)
		apartment[0][i] = i;
	for (int i = 1; i < 15; ++i)
	{
		for (int j = 1; j < 15; ++j)
		{
			if (j == 0)
				apartment[i][j] = apartment[i - 1][j];
			else
				apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
		}
	}

	cin >> test_cnt;
	while (test_cnt--)
	{
		cin >> floor >> room;
		cout << apartment[floor][room] << '\n';
	}

	return (0);
}