#include <iostream>
#include <set>

int main() {
	int N;

	std::cin >> N;

	std::set<std::string> s;

	while (N--) {
		std::string name, log;
		std::cin >> name >> log;

		if (log == "enter") {
			s.insert(name);
		} else {
			s.erase(name);
		}
	}

	auto it = s.rbegin();
	for (; it != s.rend(); ++it)
		std::cout << *it << '\n';
	
	return 0;
}