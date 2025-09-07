#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX (100000)

int main() {
	int n, k;
	std::cin >> n >> k;

	std::vector<bool> visited(MAX + 1, false);
	std::queue<int> q;
	bool hasFound = false;
	int cost = 0;
	int count = 0;

	q.push(n);
	for (; !hasFound; ++cost) {
		int size = q.size();
		while (size--) {
			int node = q.front();
			q.pop();

			visited[node] = true;

			if (node == k) {
				hasFound = true;
				count++;
			}

			if (node - 1 >= 0 && !visited[node - 1]) {
				q.push(node - 1);
			}
			if (node + 1 <= MAX && !visited[node + 1]) {
				q.push(node + 1);
			}
			if (node * 2 <= MAX && !visited[node * 2]) {
				q.push(node * 2);
			}
		}
	}

	std::cout << cost - 1 << '\n'
		<< count << '\n';

	return 0;
}