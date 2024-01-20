#include <iostream>
#include <stack>
#include <queue>

int main(void)
{
	int n;
	std::stack<int> st;
	std::queue<char> ans;
	std::queue<int> input;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		std::cin >> tmp;
		input.push(tmp);
	}

	for (int i = 1; i <= n; ++i) {
		st.push(i);
		ans.push('+');
		while (!st.empty() && !input.empty() && st.top() == input.front()) {
			st.pop();
			input.pop();
			ans.push('-');
		}
	}

	if (!st.empty()) {
		std::cout << "NO\n";
	} else {
		while (!ans.empty()) {
			std::cout << ans.front();
			ans.pop();
			if (!ans.empty()) {
				std::cout << '\n';
			}
		}
	}
	
	return 0;
}