// <https://www.acmicpc.net/problem/2961_2>
// 2961_2번 

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_CNT (1023)

using namespace std;

signed main() {
	fastio;

	int ingredient_cnt = 0;
	ll	ans = LONG_MAX;
	cin >> ingredient_cnt;
	int limit = 1 << ingredient_cnt;
	vector< pii > ingre;
	ingre.resize(ingredient_cnt);
	for (int i = 0; i < ingredient_cnt; ++i)
		cin >> ingre[i].first >> ingre[i].second;
	for (int idx = 1; idx < limit; ++idx)
	{
		ll sour_sum = 1;
		ll bitter_sum = 0;
		for (int i = 0; i < ingredient_cnt; ++i)
		{
			if (idx & (1 << i))
			{
				sour_sum *= ingre[i].first;
				bitter_sum += ingre[i].second;
			}
		}
		ans = min(ans, abs(sour_sum - bitter_sum));
	}
	cout << ans;
	return (0);
}
