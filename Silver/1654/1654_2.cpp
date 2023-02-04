// <https://www.acmicpc.net/problem/1654_2>
// 1654_2번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX (10000)
using namespace std;

static ll lines[MAX] = {0, };
static ll lines_cnt = 0;
static ll needed_cnt = 0;
static ll ans = 0;

ll get_line_cnt(ll len)
{
	ll res = 0;
	if (len == 0)
		len = 1;
	for (int i = 0; i < lines_cnt; ++i)
	{
		res += lines[i] / len;
	}
	return (res);
}

void b_search(ll left, ll right)
{
	while (left <= right)
	{
		ll mid = left * 0.5 + right * 0.5;
		ll cnt = get_line_cnt(mid);
		if (cnt >= needed_cnt)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}	
}

signed main() {
	fastio;

	cin >> lines_cnt >> needed_cnt;
	for (int i = 0; i < lines_cnt; ++i)
		cin >> lines[i];

	sort(lines, lines + lines_cnt);	
	b_search(1, lines[lines_cnt - 1]);
	cout << ans;
	return (0);
}