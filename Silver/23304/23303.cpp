// https://www.acmicpc.net/problem/23303
// 23303번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ANSWER_PROMPT ("AKARAKA")
#define WRONG_PROMPT ("IPSELENTI")

using namespace std;

static bool solve(const string &s) 
{
	int len = s.length();
	if (len == 1)
		return (true);
	string left = s.substr(0, len / 2);
	string right = s.substr((len + 1) / 2, len / 2);
	if (left != right)
		return (false);
	return (solve(left) && solve(right));
}

signed main() {
	fastio;
	string s;
	cin >> s;
	if (solve(s))
		cout << ANSWER_PROMPT;
	else
		cout << WRONG_PROMPT;
	return (0);
}