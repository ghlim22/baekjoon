#include <algorithm>
#include <iostream>
#include <vector>

int f(const std::string &s)
{
	const int n = s.size();
	int maxlen = 0;
	std::vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		v[i] = 0;
		int k = i;
		for (int j = i + 1; j < n; ++j) {
			while (k > i && s[j] != s[k]) {
				k = v[k - 1] + i;
			}

			if (s[j] == s[k]) {
				v[j] = k + 1 - i;
				k += 1;
			} else {
				v[j] = 0;
			}

			maxlen = std::max(maxlen, v[j]);
		}
	}

	return maxlen;
}

int main() 
{
	std::string s;

	std::cin >> s;
	std::cout << f(s);

	return 0;
}