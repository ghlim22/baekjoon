// https://www.acmicpc.net/problem/14659
// 14659번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int arr[30000];

signed main() {
	fastio;

	int count = 0;
	int ans = 0;

	cin >> count;
	for (int i = 0; i < count; ++i)
		cin >> arr[i];
	for (int i = 0; i < count;)
	{
		int tmp = 0;
		int j;
		for (j = i + 1; j < count; ++j)
		{
			if (arr[i] < arr[j])
				break;
			else
				tmp++;
		}
		i = j;
		ans = max(tmp, ans);
	}
	
	cout << ans;

	return (0);
}