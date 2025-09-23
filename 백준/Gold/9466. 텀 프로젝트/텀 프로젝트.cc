#include <iostream>
#include <vector>


std::vector<int> input(int n) {
	std::vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> res[i];
	}
	return res;
}

int traverse_cycle(const std::vector<int> &directed, std::vector<bool> &visited_solve_context, int node) {
	int count = 0;
	int next = node;
	do {
		int curr = next;
		visited_solve_context[curr] = true;
		count += 1;
		next = directed[curr];
	} while (next != node);
	return count;
}

int find_cycle(const std::vector<int> &directed, std::vector<bool> &visited_solve_context, std::vector<bool> &visited, int node) {
	if (visited[node]) {
		// found a cycle
		return traverse_cycle(directed, visited_solve_context, node);
	}
	if (visited_solve_context[node]) {
		return 0;
	}
	visited_solve_context[node] = true;
	visited[node] = true;
	int next = directed[node];
	return find_cycle(directed, visited_solve_context, visited, next);
}

int solve(const std::vector<int> &directed, int n) {
	std::vector<bool> visited_solve_context(n + 1, false);	
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (visited_solve_context[i])
			continue;
		std::vector<bool> visited(n + 1, false);
		count += find_cycle(directed, visited_solve_context, visited, i);
	}
	return n - count;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> directed = input(n);
		std::cout << solve(directed, n) << '\n';
	}

	return 0;
}