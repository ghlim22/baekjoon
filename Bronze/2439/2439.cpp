// <https://www.acmicpc.net/problem/2439>
// 2439번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
signed main()
{
	fastio;
	int	n;
	int i;
	int	j;
	int	k;

	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		for (j = 0; j < n - i; ++j)
			cout << ' ';
		for (k = 0; k < i; ++k)
			cout << '*';
		cout << '\n';
	}
	return (0);
}