// <https://www.acmicpc.net/problem/8393>
// 8393번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() 
{
	fastio;
	int	n;
	int	sum;

	sum = 0;
	cin >> n;
	while (n--)
		sum += (n + 1);
	cout << sum;
	return (0);
}