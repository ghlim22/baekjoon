#include <algorithm>
#include <cassert>
#include <cctype>
#include <set>
#include <iostream>
#include <queue>

struct operation {
	int left_idx;
	int right_idx;
	int cost;
} OP[10];

struct state_cost {
	int64_t state;
	int cost;
	bool operator() (const state_cost &a, const state_cost &b) {
		return a.cost > b.cost;
	}
};

int N;
int A[8];
int M;
std::set<int64_t> V;

int64_t bit_representation(int arr[], int n) {
	assert(n <= N);
	int64_t ret = 0;
	for (int i = 0; i < n; ++i) {
		assert(arr[i] >= 1 && arr[i] <= 10);
		ret |= ((int64_t)arr[i] << (8 * i));
	}
	return ret;
}

int64_t erase(int64_t state, int i) {
	assert(i < N);
	return state & ~((int64_t)((1<<8) - 1) << (8 * i));
}

int get_num(int64_t state, int i) {
	assert(i < N);
	return (state >> (8 * i)) & ((1 << 8) - 1);
}

int64_t insert(int64_t state, int i, int num) {
	assert(num >= 0 && num < (1<<8));
	int64_t ret = erase(state, i);
	return ret | ((int64_t)num << (8 * i));
}

int64_t manipulate(int64_t state, int m) {
	assert(m >= 0 && m < M);
	int left = get_num(state, OP[m].left_idx);
	int right = get_num(state, OP[m].right_idx);
	int64_t manipulated = insert(state, OP[m].left_idx, right);
	manipulated = insert(manipulated, OP[m].right_idx, left);
	
	return manipulated;
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	std::cin >> M;
	for (int i = 0; i < M; ++i) {
		std::cin >> OP[i].left_idx >> OP[i].right_idx >> OP[i].cost;
		OP[i].left_idx--;
		OP[i].right_idx--;
	}

	int64_t initial_state = bit_representation(A, N);
	std::sort(A, A + N);
	int64_t sorted = bit_representation(A, N);

	int min_cost = -1;
	std::priority_queue<state_cost, std::vector<state_cost>, state_cost> Q;
	Q.push({initial_state, 0});
	while (!Q.empty()) {
		int64_t curr = Q.top().state;
		int cost = Q.top().cost;
		Q.pop();

		if (V.find(curr) != V.end()) {
			continue;
		}

		V.insert(curr);

		if (curr == sorted) {
			min_cost = cost;
			break;
		}

		for (int i = 0; i < M; ++i) {
			int64_t next = manipulate(curr, i);
			if (V.find(next) != V.end()) {
				continue;
			}
			Q.push({next, cost + OP[i].cost});
		}
	}
	
	std::cout << min_cost << std::endl;
	
	return 0;
}