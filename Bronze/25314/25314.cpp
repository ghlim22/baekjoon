// <https://www.acmicpc.net/problem/25314>
// 25314번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static const int INF = 0x3f3f3f3f;

signed main()
{
	fastio;
	int	byte;

	cin >> byte;
	byte /= 4;
	while (byte--)
		cout << "long ";
	cout << "int";
	return (0);
}