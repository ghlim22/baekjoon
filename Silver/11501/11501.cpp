// <https://www.acmicpc.net/problem/11501>
// 11501번 

#include <iostream>
#include <memory.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static int prices[1000000];

signed main() {
	fastio;
	
	int test_cnt = 0;

	cin >> test_cnt;
	for (int i = 0; i < test_cnt; ++i)
	{
		int day_cnt = 0;
		ll profit = 0;

		cin >> day_cnt;
		memset(prices, 0, sizeof(int) * 1000000);
		for (int j = 0; j < day_cnt; ++j)
			cin >> prices[j];
		
		for (int j = day_cnt - 1; j >= 0; --j)
		{
			int cur_price = prices[j];
			int k;
			for (k = j - 1; k >= 0; --k)
			{
				if (prices[k] > cur_price)
				{
					break;
				}
				profit += (cur_price - prices[k]);
			}
			j = k + 1;
		}

		cout << profit << '\n';
	}

	return (0);
}