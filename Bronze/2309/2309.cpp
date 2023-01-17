// <https://www.acmicpc.net/problem/2309>
// 2309번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define NUM (9)

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	int arr[9] = {0, };

	for (int i = 0; i < NUM; ++i)
		cin >> arr[i];
	sort(arr, arr + NUM);
	int sum = 0;
	for (int i = 0; i < NUM; ++i)
		sum += arr[i];
	for (int i = 0; i < NUM; ++i)
	{
		for (int j = 0; j < NUM; ++j)
		{
			if (i != j && sum - arr[i] - arr[j] == 100)
			{
				for (int k = 0; k < NUM; ++k)
				{
					if (k != i && k != j){
						cout << arr[k] << "\n";
					}
				}
				return ;
			}
		}
	}
}

signed main() {
	fastio;
	solve();
	return (0);
}