#include <iostream>

int main() {
	std::string s;
	std::cin >> s;

	for (int x = 0; x < 10; ++x) {
		int sum = 0;
		for (int i = 0; i < s.length() - 1; ++i) {
			int digit = s[i] - '0';
			if (s[i] == '*') {
				digit = x;
			}
			if (i % 2 != 0) {
				digit *= 3;
			}
			sum += digit;	
		}
		int m = s.back() - '0';
		if ((sum + m) % 10 == 0) {
			std::cout << x << std::endl;
			break;
		}	
	}

	return 0;
}