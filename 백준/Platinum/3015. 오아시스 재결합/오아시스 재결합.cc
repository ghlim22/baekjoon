#include <iostream>
#include <stack>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

int h[500000];
int cache[500000]; /* equal to or greater than */

long f(int h[], int c[], int n) {
	long ret = 0;
	std::stack<int> s;

	for (int i = 0; i < n; ++i) {
		int smaller = 0;
		while (!s.empty() && h[i] > h[s.top()]) {
			smaller++;
			s.pop();
		}
		if (!s.empty() && h[i] == h[s.top()]) {
			c[i] += (c[s.top()] + 1);
		}
		if (!s.empty() && h[i] < h[s.top()]) {
			c[i]++;
		}
		ret += smaller;
		ret += c[i];
		s.push(i);
	}

	return (ret);
}

int main(void) {
  fastio;

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
	std::cin >> h[i];
 
  std::cout << f(h, cache, n) << std::endl;

  return 0;
}