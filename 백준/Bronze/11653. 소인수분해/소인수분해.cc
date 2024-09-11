#include <iostream>
#include <vector>

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int n;

	std::cin >> n;
	
	for (int i = 2; n > 1; ++i) {
		while (n % i == 0) {
			std::cout << i << '\n';
			n /= i;
		}
	}

	return 0;
}
