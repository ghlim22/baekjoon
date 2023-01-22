// https://www.acmicpc.net/problem/1182_5
// 1182_5번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

signed main() {
	fastio;
	int element_cnt = 0;
	int desirable_sum = 0;
	int arr[20] = {0, };
	int ans = 0;

	cin >> element_cnt >> desirable_sum;
	for (int i = 0; i < element_cnt; ++i)
		cin >> arr[i];
	int limit = 1 << element_cnt;
	for (int i = 1; i < limit; ++i)
	{
		int sum = 0;
		for (int j = 0; j < element_cnt; ++j)
		{
			if (i & (1 << j))
				sum += arr[j];
		}
		if (sum == desirable_sum)
			ans++;
	}
	cout << ans; 
	return (0);
}