// https://www.acmicpc.net/problem/1965
// 1965번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int sizes[1000];
static int counts[1000];

signed main() {
	fastio;

	int box_count = 0;
	int ans = 0;

	cin >> box_count;
	for (int i = 0; i < box_count; ++i)
		cin >> sizes[i];

	for (int i = 0; i < box_count; ++i)
	{
		int max = 0;
		for (int j = 0; j < i; ++j)
		{
			if (sizes[j] < sizes[i] && max < counts[j])
				max = counts[j];
		}
		counts[i] = max + 1;
		if (counts[i] > ans)
			ans = counts[i];
	}

	cout << ans;

	return (0);
}