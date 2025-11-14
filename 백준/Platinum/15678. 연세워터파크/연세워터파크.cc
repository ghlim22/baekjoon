#include <algorithm>
#include <deque>
#include <iostream>

#define LMT (100000)
#define MIN (-1000000000)

long cache[LMT + 1];
int n;
int d;

int main() {
	std::cin >> n >> d;
	std::deque<int> dq;
	for (int i = 1; i <= n; ++i) {
		int elem;
		std::cin >> elem;
		cache[i] = elem;
		while (!dq.empty() && dq.front() < i - d) {
			dq.pop_front();	
		}
		if (!dq.empty()) {
			cache[i] = std::max(cache[i], cache[dq.front()] + elem);
		}
		while (!dq.empty() && cache[dq.back()] < cache[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	std::cout << *std::max_element(cache + 1, cache + 1 + n);

	return 0;
}