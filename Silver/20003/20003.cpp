// https://www.acmicpc.net/problem/20003
// 20003번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

static long long get_gcd(long long a, long long b)
{
	if (b == 0)
		return (a);
	return (get_gcd(b, a % b));
}

signed main() {
	fastio;
	int item_cnt = 0;
	long long lcm = 1;
	long long gcd = 0;

	cin >> item_cnt;
	for (int i = 0; i < item_cnt; ++i)
	{
		long long numerator;
		long long denominator;

		cin >> numerator >> denominator;
		long long tmp_gcd = get_gcd(numerator, denominator);
		numerator /= tmp_gcd;
		denominator /= tmp_gcd;
		gcd = get_gcd(numerator, gcd);
		lcm = lcm / get_gcd(denominator, lcm) * denominator;
	}
	cout << gcd << ' ' << lcm;
	return (0);
}