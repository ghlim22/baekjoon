#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int cnt[100001];

std::vector<int> preprocess(const std::string& s)
{
	int n = s.size();
	std::vector<int> fail(n);
	fail[0] = 0;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (j > 0 && s[i] != s[j]) {
			j = fail[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
			fail[i] = j;
		}
		else {
			fail[i] = 0;
		}
	}
	return fail;
}

std::vector<std::pair<int, int>> solve(const std::vector<int>& fail)
{
	int n = fail.size();
	for (int i = 0; i < n; ++i) {
		cnt[fail[i]] += 1;
	}
	for (int i = n; i > 0; --i) {
		cnt[fail[i - 1]] += cnt[i];
	}
	std::vector<std::pair<int, int>> result;
	for (int i = n; i > 0; i = fail[i - 1]) {
		result.push_back({ i, cnt[i] + 1 });
	}
	std::reverse(result.begin(), result.end());
	return result;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);
	std::string S;

	std::cin >> S;
	auto fail = preprocess(S);
	auto result = solve(fail);
	std::cout << result.size() << '\n';
	for (auto p : result) {
		std::cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}