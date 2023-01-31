// https://www.acmicpc.net/problem/20921
// 20921번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;

	int cnt = 0;
	int k = 0;
	int ans_idx = 0;

	cin >> cnt >> k;
	int people[cnt];
	int arr[cnt];
	bool used[cnt];

	for (int i = 0; i < cnt; ++i)
		used[i] = false;
	for (int i = 0; i < cnt; ++i)
		people[i] = i + 1;

	while (k > 0)
	{
		for (int i = cnt - 1; i >= 0; --i)
		{
			if (!used[i] && people[i] - 1 <= k)
			{
				k -= people[i] - 1;
				used[i] = true;
				arr[ans_idx++] = people[i];
			}
		}
	}

	while (ans_idx < cnt)
	{
		for (int i = 0; i < cnt; ++i)
		{
			if (!used[i])
			{
				used[i] = true;
				arr[ans_idx++] = people[i];
			}
			if (ans_idx >= cnt)
				break ;
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		cout << arr[i] << ' ';
	}
	
	return (0);
}