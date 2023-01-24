// https://www.acmicpc.net/problem/13241
// 13241번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

unsigned long long get_gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0)
	{
		return (a);
	}
	return (get_gcd(b, a % b));
}

signed main() {
	fastio;
	unsigned long long a, b;
	cin >> a >> b;
	unsigned long long _lcm = a / get_gcd(a, b) * b;
	cout << _lcm;
	return (0);
}