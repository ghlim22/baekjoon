// <https://www.acmicpc.net/problem/9625>
// 9625번 

#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static pii counts[46];

void solve(int cnt) 
{
	counts[1].first = 0;
	counts[1].second = 1;
	for (int i = 2; i <= cnt; ++i)
	{
		counts[i].first = counts[i - 1].second;
		counts[i].second = counts[i - 1].first + counts[i - 1].second;
	}
	cout << counts[cnt].first << ' ' << counts[cnt].second;
	return;
}

signed main() {
	fastio;
	int cnt = 0;
	
	cin >> cnt;

	solve(cnt);

	return (0);
}