#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int get_abs(int num)
{
	return ((num < 0) ? -num : num);
}

static int get_gcd(int a, int b)
{
	if (!b)
		return (a);
	return (get_gcd(b, a % b));
}

void solve() {
	
}

signed main() {
	fastio;
	int n, s;
	int gcd = 0;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
	{
		int location;
		cin >> location;
		gcd = get_gcd(get_abs(location - s), gcd);
	}
	cout << gcd;
	return (0);
}