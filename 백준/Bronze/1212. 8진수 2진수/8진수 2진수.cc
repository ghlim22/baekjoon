#include <iostream>
#include <queue>
#include <valarray>

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::string octal;
	std::queue<int> binary;

	std::cin >> octal;

	for (int i = 0; i < octal.size(); ++i) {
		int octalDigit = octal[i] - '0';
		for (int j = 2; j >= 0; --j) {
			binary.push((octalDigit >> j) & 1);
		}
	}

	while (binary.size() > 1 && binary.front() == 0) {
		binary.pop();
	}

	while (!binary.empty()) {
		std::cout << binary.front();
		binary.pop();
	}

	return 0;
}
