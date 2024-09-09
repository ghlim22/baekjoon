#include <iostream>
#include <valarray>
#include <vector>


int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::string binary;
	std::vector<int> octal;

	std::cin >> binary;

	for (int i = binary.size() - 1; i >= 0; i -= 3) {
		int octalDigit = 0;
		for (int j = 0; j < 3 && i - j >= 0; ++j) {
			octalDigit += (binary[i - j] - '0') << j;
		}
		octal.push_back(octalDigit);
	}

	for (int i = octal.size() - 1; i >= 0; --i) {
		std::cout << octal[i];
	}

	return 0;
}
