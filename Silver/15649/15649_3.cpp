// <https://www.acmicpc.net/problem/15649_3>
// 15649_3번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
static int n;
static int m;
static int arr[8];
static bool used[9];

void solve(int level) 
{
	if (level == m)
	{
		for (int i = 0; i < level; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!used[i]){
			used[i] = true;
			arr[level] = i;
			solve(level + 1);
			used[i] = false;
		}
	}	
}

signed main() {
	fastio;

	cin >> n >> m;
	solve(0);
	return (0);
}