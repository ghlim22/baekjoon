#include <iostream>
#include <vector>

std::vector<int> preprocess(const std::string &s)
{
	int n = s.size();
	std::vector<int> f(n);
	f[0] = 0;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (j > 0 && s[i] != s[j]) {
			j = f[j - 1];
		}
		if (s[i] == s[j]) {
			f[i] = j + 1;
			j++;
		} else {
			f[i] = 0;
		}
	}
	return f;
}

int find(const std::string s, const std::vector<int> fail)
{
	int n = s.size();
	for (int m = fail[n - 1]; m > 0; m = fail[m - 1]) {
		int start = m - fail[m - 1];
		int end = n - start;
		int j = 0;
		for (int i = start; i < end; ++i) {
			while (j > 0 && s[i] != s[j]) {
				j = fail[j - 1];
			}
			if (s[i] == s[j]) {
				j++;
				if (j == m) {
					return m;
				}
			}
		}
	}
	return -1;
}

int main()
{
	std::string S;
	std::cin >> S;
	auto f = preprocess(S);
	int len = find(S, f);
	if (len == -1) {
		std::cout << -1;
	} else {
		std::cout << S.substr(0, len);
	}
	
	return 0;
}