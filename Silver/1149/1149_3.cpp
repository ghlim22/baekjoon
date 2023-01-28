// https://www.acmicpc.net/problem/1149_3
// 1149_3번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int arr[1000001];

signed main() {
	fastio;

	int num = 0;

	cin >> num;
	for (int i = 2; i <= num; ++i)
	{
		arr[i] = arr[i - 1];
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2]);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3]);
		arr[i]++;
	}
	cout << arr[num];

	return (0);
}