// <https://www.acmicpc.net/problem/1182_4>
// 1182_4번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
static int n;
static int s;
static int ans;
static int arr[20];

void solve(int sum, int idx, int cnt) 
{
	if (idx == n)
	{
		if (cnt > 0 && sum == s)
		{
			ans++;
		}
		return ;
	}
	solve(sum + arr[idx], idx + 1, cnt + 1); // 현재 원소를 더한다.
	solve(sum, idx + 1, cnt); // 현재 원소를 더하지 않는다.
}

signed main() 
{
	fastio;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	solve(0, 0, 0);
	cout << ans;
	return (0);
}