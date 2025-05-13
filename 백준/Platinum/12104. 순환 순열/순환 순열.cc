#include <iostream>
#include <vector>

std::vector<int> preprocess(const std::string &s)
{
	int n = s.size();
	int j = 0;
	std::vector<int> fail(n);
	fail[0] = 0;
	for (int i = 1; i < n; ++i) {
		while (j > 0 && s[j] != s[i]) {
			j = fail[j - 1];
		}
		if (s[j] == s[i]) {
			fail[i] = j + 1;
			j++;
		} else {
			fail[i] = 0;
		}
	}
	return fail;
}

int match(const std::string &s, const std::string &p, const std::vector<int> &f)
{
	int count = 0;
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && s[i] != p[j]) {
			j = f[j - 1];
		}
		if (s[i] == p[j]) {
			j++;
			if (j == m) {
				j = f[j - 1];
				count++;
			}
		}
	}

	return count;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);
	
	std::string A, B;
	std::cin >> A >> B;
	B += B;
	B.pop_back();
	auto f = preprocess(A);
	std::cout << match(B, A, f);
	
	return 0;
}