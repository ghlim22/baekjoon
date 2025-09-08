#include <algorithm>
#include <iostream>

#define MOD (1'000'000'007L)

int gcd(int a, int b) {
	if (a < b) std::swap(a, b);

	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;	
	}

	return a;
}

long power(long a, long b, long m) {
	long base = a % m;
	long ret = 1;
	while (b > 0) {
		if (b & 1) {
			ret = ret * base % m;
		}
		base = base * base % m;
		b = b >> 1;
	}
	return ret;
}

int main() {
	int m;
	std::cin >> m;
	long ret = 0;
	while (m--) {
		long n, s;
		std::cin >> n >> s;
		long d = gcd(n, s);
		n = n / d;
		s = s / d;
		ret = ret + (s * power(n, MOD - 2, MOD)) % MOD;
		ret = ret % MOD;
	}

	std::cout << ret;

	return 0;
}
