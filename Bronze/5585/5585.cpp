// https://www.acmicpc.net/problem/5585
// 5585번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define pii pair<int, int>

using namespace std;

signed main() {
	fastio;
	int input = 0;
	int ans = 0;
	int arr[5] = {500, 100, 50, 10, 5};

	cin >> input;
	int num = 1000 - input;
	for (int i = 0; i < 5; ++i)
	{
		ans += (num / arr[i]);
		num %= arr[i];
	}
	cout << ans + num;

	return (0);
}