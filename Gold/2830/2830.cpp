// https://www.acmicpc.net/problem/2830
// 2830번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long

using namespace std;

signed main() {
	fastio;

	ll ans = 0;
	int n;
	int arr[20] = {0, };

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;

		cin >> tmp;
		for (int j = 0; j < 20; ++j)
		{
			if (tmp & (1 << j))
				arr[j]++;
		}
	}
	
	for (int i = 0; i < 20; ++i)
	{
		ans += (1LL << i) * (n - arr[i]) * arr[i];
	}

	cout << ans;

	return (0);
}