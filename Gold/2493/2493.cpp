// https://www.acmicpc.net/problem/2493
// 2493번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static const int INF = 0x3f3f3f3f;

int arr[500000];
int ans[500000];
int ans_height[500000];

void solve() 
{
	int n = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		
		cin >> tmp;
		arr[i] = tmp;
		if (i == 0)
			continue;
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] > arr[i])
			{
				ans[i] = j + 1;
				ans_height[i] = arr[j];
				break ;
			}
			if (ans_height[j] > tmp)
			{
				ans[i] = ans[j];
				ans_height[i] = ans_height[j];
				break ;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i];
		if (i < n - 1)
			cout << " ";
	}
}

signed main() 
{
	fastio;
	solve();
	return (0);
}