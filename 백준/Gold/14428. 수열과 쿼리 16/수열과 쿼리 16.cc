#include <cstdio>
#define SIZE 100000

int seq[SIZE + 1];
int tree[SIZE * 4];

int construct(int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
		return tree[node];
	}

	int mid = (start + end) / 2;
	int left_index = construct(node * 2, start, mid);
	int right_index = construct(node * 2 + 1, mid + 1, end);
	if (seq[left_index] <= seq[right_index]) {
		tree[node] = left_index;
	} else {
		tree[node] = right_index;
	}

	return tree[node];
}

int update(int node, int start, int end, int index, int newval) {
	if (index < start || index > end) {
		return tree[node];
	}
	if (start == end) {
		seq[index] = newval;
		tree[node] = index;
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left_index = update(node * 2, start, mid, index, newval);
	int right_index = update(node * 2 + 1, mid + 1, end, index, newval);
	if (seq[left_index] <= seq[right_index]) {
		tree[node] = left_index;
	} else {
		tree[node] = right_index;
	}
	return tree[node];
}

int find(int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left_index = find(node * 2, start, mid, left, right);
	int right_index = find(node * 2 + 1, mid + 1, end, left, right);
	if (seq[left_index] <= seq[right_index]) {
		return left_index;
	} else {
		return right_index;
	}
}

int main() {
	int n, m;
	std::scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		std::scanf("%d", &seq[i]);
	}
	seq[0] = 1e9+1;
	construct(1, 1, n);
	std::scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		std::scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			update(1, 1, n, b, c);
		} else {
			int idx = find(1, 1, n, b, c);
			std::printf("%d\n", idx);
		}
	}
	return 0;
}