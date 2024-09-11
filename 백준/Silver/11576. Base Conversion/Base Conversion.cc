#include <iostream>
#include <vector>

int main(void)
{
	std::cin.tie(NULL)->sync_with_stdio(false);

	int a;
	int b;
	int m;
	int inDigit;
	int inValue = 0;

	std::vector<int> output;

	std::cin >> a >> b >> m;

	for (int i = m - 1; i >= 0; --i) {
		std::cin >> inDigit;
		for (int j = 0; j < i; ++j) {
			inDigit *= a;
		}
		inValue += inDigit;
	}

	while (inValue != 0) {
		output.push_back(inValue % b);
		inValue /= b;
	}

	for (int i = output.size() - 1; i >= 0; --i) {
		std::cout << output[i];
		if (i > 0) {
			std::cout << ' ';
		}
	}

	return 0;
}
