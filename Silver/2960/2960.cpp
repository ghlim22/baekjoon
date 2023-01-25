// <https://www.acmicpc.net/problem/2960>
// 2960번 

#include <iostream>
#include <memory.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;
	int n = 0;
	int k = 0;
	int cnt = 0;
	bool visited[1001];

	memset(visited, 0, sizeof(bool) * 1001);
	cin >> n >> k;
	for (int i = 2; i <= n; ++i){
		if (!visited[i])
		{
			++cnt;
			if (cnt == k)
			{
				cout << i;
				return (0);
			}
			for (int j = i * i; j <= n; j += i){
				if (!visited[j])
				{
					visited[j] = true;
					++cnt;
					if (cnt == k)
					{
						cout << j;
						return (0);
					}
				}
			}
		}
	}

	return (0);
}