#include <iostream>
#include <queue>
#include <valarray>

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;
	const int base = 2;
	std::vector<int> output;

	std::cin >> n;

	/*
	a / (-r) = c remainder d.
	We use the remainder to determine each digit of the converted number.
	In most programming languages, the result (in integer arithmetic) of 
	dividing a negative number by a negative number is rounded towards 0,
	usually leaving a negative remainder.
	a = (-r)c + d = (-r)c + d + r - r = (-r)(c + 1) + (d + r)
	Because abs(d) < r, (d + r) is the positive remainder.
	*/

	do {
		int quotient = n / (-base);
		int remainder = n % (-base);
		if (remainder < 0) {
			quotient += 1;
			remainder += base;
		}
		n = quotient;
		output.push_back(remainder);
	} while (n != 0);

	for (int i = output.size() - 1; i >= 0; --i) {
		std::cout << output[i];
	}

	return 0;
}
