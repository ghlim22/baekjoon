#include <stdio.h>

long power(long base, long exp, long modulus) {
	long retval = 1;
	while (exp > 0) {
		if (exp & 1) {
			retval = (retval * base) % modulus;
		}
		base = ((base % modulus) * (base % modulus)) % modulus;
		exp >>= 1;
	}
	return retval;
}

long comb(int n, int k, int modulus) {
	if (k == 0 || n == k) {
		return 1;
	}

	long a = 1;
	for (long i = n; i > n - k; --i) {
		a = (a * i) % modulus;
	}
	long b = 1;
	for (long i = 1; i <= k; ++i) {
		b = (b * i) % modulus;
	}

	long retval = ((a % modulus) * (power(b, modulus - 2, modulus) % modulus)) % modulus;

	return retval;
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	const int modulus = 1000000007;

	long retval = comb(n, k, modulus);
	printf("%ld", retval);

	return 0;
}