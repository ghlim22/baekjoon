#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

static int n;
static int m;
static int arr[7];

void solve(int lv) 
{
	if (lv == m)
	{
		for (int i = 0; i < lv; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}

	for (int i = 1; i <= n; ++i)
	{
		arr[lv] = i;
		solve(lv + 1);
	}
}

signed main() {
	fastio;
	cin >> n >> m;
	solve(0);
	return (0);
}