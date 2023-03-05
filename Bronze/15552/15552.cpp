// <https://www.acmicpc.net/problem/15552>
// 15552번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main()
{
	fastio;
	int	test_cnt;
	int	a;
	int	b;

	cin >> test_cnt;
	while (test_cnt--)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return (0);
}