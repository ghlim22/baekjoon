// https://www.acmicpc.net/problem/3078
// 3078번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;
	int N, K;
	long long ans = 0;
	int name_len[21] = {0, };
	int arr[300000] = {0, };
	string input;

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		arr[i] = input.length();
	}
	// creating window.
	for (int i = 0; i <= K && i < N; ++i)
	{
		name_len[arr[i]]++;
	}
	for (int i = 0; i < N; ++i)
	{
		ans += (name_len[arr[i]] -= 1);
		if (++K < N)
			name_len[arr[K]]++;
	}
	cout << ans;

	return (0);
}
