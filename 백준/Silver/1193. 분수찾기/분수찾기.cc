#include <iostream>

int main() {
	int x;
	std::cin >> x;

	int a = 1;
	int b = 1;

	int n = 1;
	bool down = false;
	while (n < x) {
		if (a == 1) {
			if (b % 2 != 0) {
				b++;
				n++;
			} else {
				down = true;
				a++;
				b--;
				n++;
			}
		} else if (b == 1) {
			if (a % 2 != 0) {
				down = false;
				a--;
				b++;
				n++;
			} else {
				a++;
				n++;
			}
		} else if (down) {
			n++;
			a++;
			b--;
		} else {
			n++;
			a--;
			b++;
		}
	}

	std::cout << a << '/' << b;
}