// <https://www.acmicpc.net/problem/25304>
// 25304번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() 
{
	fastio;
	int	receipt_total;
	int	num_types;
	int	price;
	int	cnt;
	int	sum;

	sum = 0;
	cin >> receipt_total;
	cin >> num_types;
	while (num_types--)
	{
		cin >> price >> cnt;
		sum += price * cnt;
	}
	if (sum == receipt_total)
		cout << "Yes";
	else
		cout << "No";
	return (0);
}