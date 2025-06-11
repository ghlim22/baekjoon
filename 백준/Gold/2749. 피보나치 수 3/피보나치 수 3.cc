#include <iostream>
#include <vector>

int main()
{
	long long  n;
	int m = 1000000;

	std::cin >> n;
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);

	int p = 2;
	while (!(v[p] == v[1] && v[p - 1] == v[0])) {
		v.push_back((v[p] + v[p - 1]) % m);
		p++;
	}
	p--;

	std::cout << v[n % p];

	return 0;
}