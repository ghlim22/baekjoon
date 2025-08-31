#include <cctype>
#include <string>
#include <iostream>

bool isNumber(const std::string &s) {
	for (char c : s) {
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

int main() {
	std::string s[3];

	std::cin >> s[0] >> s[1] >> s[2];

	for (int i = 2; i >= 0; --i) {
		if (isNumber(s[i])) {
			int answer = std::stoi(s[i]) + (3-i);
			if (answer % 3 == 0 && answer % 5 == 0)
				std::cout << "FizzBuzz";
			else if (answer % 3 == 0)
				std::cout << "Fizz";
			else if (answer % 5 == 0)
				std::cout << "Buzz";
			else
				std::cout << answer;
			return 0;
		}
	}


	bool found = false;
	for (int i = 4; !found; ++i) {
		int x = i - 3;
		int count = 0;
		for (int j = 0; j < 3; ++j) {
			int y = x + j;
			if (y % 3 == 0 && y % 5 == 0) {
				if (s[j] == "FizzBuzz")
					count += 1;
			} else if (y % 3 == 0) {
				if (s[j] == "Fizz")
					count += 1;
			} else if (y % 5 == 0) {
				if (s[j] == "Buzz")
					count += 1;
			} else {
				if (isNumber(s[j]) && std::stoi(s[j]) == y)
					count += 1;
			}
		}

		if (count == 3) {
			if (i % 3 && i % 5 == 0)
				std::cout << "FizzBuzz";
			else if (i % 3 == 0)
				std::cout << "Fizz";
			else if (i % 5 == 0)
				std::cout << "Buzz";
			else
				std::cout << i;
			std::cout << std::endl;
			found = true;
		}
	}

	return 0;
}