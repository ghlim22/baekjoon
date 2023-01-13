// <https://www.acmicpc.net/problem/1377>
// 1377번 

#include <iostream>
#include <utility>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

signed main() 
{
	fastio;
	int N;

	cin >> N;
	pair<int, int> arr[N];
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		arr[i].first = input;
		arr[i].second = i;
	}
	sort(arr, arr + N);
	int ans = 0;
	for (int i = 0; i < N; ++i)
		ans = max(ans, arr[i].second - i);
	cout << (ans + 1) << "\n";
	return 0;
}