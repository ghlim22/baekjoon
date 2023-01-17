// <https://www.acmicpc.net/problem/9663_2>
// 9663_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
static int ans;
static int n;
static bool col[15];
static bool di1[15 * 2 - 1];
static bool di2[15 * 2 - 1];

void solve(int level) 
{
	if (level == n)
	{
		ans++;
		return ;
	}	

	for (int i = 0; i < n; ++i)
	{
		if (!col[i] && !di1[i + level] && !di2[n - i + level - 1])
		{
			col[i] = true;
			di1[i + level] = true;
			di2[n - i + level - 1] = true;
			solve(level + 1);
			col[i] = false;
			di1[i + level] = false;
			di2[n - i + level - 1] = false;
		}
	}
}

signed main() 
{
	fastio;
	cin >> n;
	solve(0);
	cout << ans;
	return (0);
}