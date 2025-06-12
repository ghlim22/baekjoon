#include <climits>
#include <iostream>
#include <set>
#include <vector>

long long K;
long long max = 100000;
std::vector<int> primes;
std::vector<bool> check(max + 1);

long long f(int index, long long num, long long m)
{
	if (index == primes.size()) {
		return 0;
	}
	if (num * primes[index] > m) {
		return 0;
	}

	long long ret = 0;
	ret += m / (num * primes[index]);
	ret += f(index + 1, num, m);
	ret -= f(index + 1, num * primes[index], m);

	return ret;
}

long long solve()
{
	long long left = 1;
	long long right = INT_MAX;
	while (left < right) {
		long long mid = (left + right) / 2;
		long long cnt = mid - f(0, 1, mid);
		if (cnt >= K) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

int main()
{
	std::cin >> K;

	for (int i = 2; i <= max; ++i) {
		if (check[i])
			continue;
		
		primes.push_back(i * i);
		for (int j = i + i; j <= max; j += i) {
			check[j] = true;
		}
	}

	std::cout << solve() << std::endl;

	return 0;
}