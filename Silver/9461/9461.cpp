// https://www.acmicpc.net/problem/9461
// 9461번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static ll arr[100];

void solve() {
	
}

signed main() {
	fastio;

	int test_cnt = 0;

	cin >> test_cnt;

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 2;

	for (int i = 5; i < 100; ++i)
	{
		arr[i] = arr[i - 5] + arr[i - 1];
	}

	for (int i = 0; i < test_cnt; ++i)
	{
		int input;

		cin >> input;
		cout << arr[input - 1] << '\n';
	}

	return (0);
}