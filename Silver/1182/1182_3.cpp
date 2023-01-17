// <https://www.acmicpc.net/problem/1182_3>
// 1182_3번 

#include <iostream>
#include <math.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
static int n;
static int s;
static int ans;
static int arr[21];

void solve() {
	
	
}

signed main() {
	fastio;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int limit = (int)pow(2, n);
	for (int i = 1; i <= limit; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			if ((i >> j) & 0x1)
			{
				sum += arr[j];
			}
		}
		if (sum == s)
			ans++;
	}
	if (s == 0)
		ans--;
	cout << ans;
	return (0);
}