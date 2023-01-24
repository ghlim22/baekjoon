// https://www.acmicpc.net/problem/14490
// 14490번 

#include <stdio.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;


static long long get_gcd(long long a, long long b)
{
	if (!b)
		return (a);
	return (get_gcd(b, a % b));
}

signed main() {
	long long n ,m;

	scanf("%lld:%lld", &n, &m);
	long long gcd = get_gcd(n, m);
	printf("%lld:%lld", n / gcd, m / gcd);
	return (0);
}