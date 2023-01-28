// https://www.acmicpc.net/problem/2748
// 2748번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static ll arr[91];

signed main() {
	fastio;
	int input = 0;

	cin >> input;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= input; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[input];
	
	return (0);
}