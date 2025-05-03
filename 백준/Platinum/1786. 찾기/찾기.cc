#include <iostream>
#include <vector>

std::vector<int> preprocess(const std::string &s)
{
	const int n = s.size();
	std::vector<int> v(n);
	v[0]=0;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (j > 0 && s[i] != s[j]) {
			j = v[j - 1];
		}
		if (s[i] == s[j]) {
			v[i] = j + 1;
			j++;
		} else {
			v[i] = 0;
		}
	}
	return v;
}

std::vector<int> kmp(const std::string &t, const std::string &p)
{
	const int n = t.size();
	const int m = p.size();
	auto v = preprocess(p);
	std::vector<int> answer;

	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && t[i] != p[j]) {
			j = v[j - 1];
		}

		if (t[i] == p[j]) {
			if (j == m - 1) {
				answer.push_back(i - m + 1);
				j = v[j];
			} else {
				j++;
			}
		}
	}

	return answer;
}

int main() 
{
	std::string T, P;

	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	std::getline(std::cin, T);
	std::getline(std::cin, P);

	auto v = kmp(T, P);

	std::cout << v.size() << '\n';
	for (auto i : v) {
		std::cout << i + 1 << ' ';
	}
	return 0;
}