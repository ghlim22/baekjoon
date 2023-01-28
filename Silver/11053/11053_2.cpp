// https://www.acmicpc.net/problem/11053_2
// 11053_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int nums[1000];
static int len[1000];

signed main() {
	fastio;

	int size = 0;
	int ans = 0;

	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int max_len = 0;
		cin >> nums[i];
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i] && len[j] > max_len)
				max_len = len[j];
		}
		len[i] = max_len + 1;
		if (len[i] > ans)
			ans = len[i];
	}
	cout << ans;

	return (0);
}