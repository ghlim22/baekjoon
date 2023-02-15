// <https://www.acmicpc.net/problem/2961_2>
// 2961_2번 

#include <iostream>
#include <cmath>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_CNT (1023)

using namespace std;

static int sour_arr[10];
static int bitter_arr[10];
static ll sour_sum[MAX_CNT];
static ll bitter_sum[MAX_CNT];
static int sour_cnt = 0;
static int bitter_cnt = 0;

signed main() {
	fastio;

	int ingredients_cnt = 0;
	cin >> ingredients_cnt;
	for (int i = 0; i < ingredients_cnt; ++i)
		cin >> sour_arr[i] >> bitter_arr[i];
	int limit = (int)pow(2, ingredients_cnt);
	for (int i = 1; i < limit; ++i)
	{
		sour_sum[sour_cnt] = 1;
		for (int j = 0; j < ingredients_cnt; ++j)
		{
			if ((i >> j) & 1)
				sour_sum[sour_cnt] *= sour_arr[j];
		}
		sour_cnt++;
	}
	for (int i = 1; i < limit; ++i)
	{
		for (int j = 0; j < ingredients_cnt; ++j)
		{
			if ((i >> j) & 1)
				bitter_sum[bitter_cnt] += bitter_arr[j];
		}
		bitter_cnt++;
	}
	ll ans = abs(sour_sum[0] - bitter_sum[0]);
	for (int i = 1; i < sour_cnt; ++i)
	{
		ans = min(ans, abs(sour_sum[i] - bitter_sum[i]));
	}	
	cout << ans;
	return (0);
}
