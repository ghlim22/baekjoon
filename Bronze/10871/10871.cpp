// <https://www.acmicpc.net/problem/10871>
// 10871번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
signed main()
{
	fastio;
	int	n;
	int	x;
	int	tmp;

	cin >> n >> x;
	while (n--)
	{
		cin >> tmp;
		if (tmp < x)
			cout << tmp << ' ';
	}
	return (0);
}