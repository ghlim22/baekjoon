// <https://www.acmicpc.net/problem/11726>
// 11726번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define FACTOR (10007)

using namespace std;

static int arr[1001];

signed main() {
	fastio;

	int n = 0;

	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; ++i)
		arr[i] = (arr[i - 1] % FACTOR + arr[i - 2] % FACTOR) % FACTOR;
	cout << arr[n] % FACTOR;
	return (0);
}