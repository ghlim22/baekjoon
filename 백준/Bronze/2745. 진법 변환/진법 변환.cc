#include <iostream>
#include <vector>

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::string input;
	int base;
	int output = 0;

	std::cin >> input;
	std::cin >> base;

	for (int i = 0; i < input.size(); ++i) {
		int digit = input[input.size() - 1 - i];
		if (isdigit(digit)) {
			digit -= '0';
		} else {
			digit -= 'A';
			digit += 10;
		}
		for (int j = 0; j < i; ++j) {
			digit *= base;
		}
		output += digit;
	}

	std::cout << output;

	return 0;
}
