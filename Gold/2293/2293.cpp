// <https://www.acmicpc.net/problem/2293>
// 2293번 

#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static vector<int> coins;
static int cases[10001];

signed main() {
	fastio;

	int coin_cnt = 0;
	int dest_sum = 0;

	cin >> coin_cnt >> dest_sum;
	for (int i = 0; i < coin_cnt; ++i){
		int input;

		cin >> input;
		coins.push_back(input);
	}
	cout << '\n';
	cases[0] = 0;
	for (int i = 1; i <= dest_sum; ++i)
	{
		int j;
		int k = 0;
		for (j = i - 1; j > 0; --j)
		{
			for (k = 0; k < coin_cnt; ++k)
			{
				if ((i - j) % coins[k] == 0){
					//cout << i << j << k << '\n';
					goto GET;
				}
			}	
		}
		GET:
		if (j != 0)
			cases[i] = cases[j];
		else
			cases[i] = 0;
		
		for (int l = 0; l < coin_cnt; ++l)
		{
			if ((j == 0 || l != k) && i % coins[l] == 0)
				cases[i]++;
		}
		cout << cases[i] << '\n';
	}
	cout << cases[dest_sum];

	return (0);
}