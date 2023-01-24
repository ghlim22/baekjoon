// https://www.acmicpc.net/problem/1850
// 1850번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;
	unsigned long long a, b, cnt = 0;

	cin >> a >> b;
	while (b > 0)
	{
		unsigned long long tmp_a, tmp_b;
		tmp_a = a;
		tmp_b = b;
		a = b;
		b = tmp_a % tmp_b;
	}
	cnt = a;
	for (int i = 0; i < cnt; ++i)
		cout << '1';
	return (0);
}