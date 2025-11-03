#include <cstdio>
#define SIZE 1000000

long seq[SIZE + 1];
long tree[SIZE * 4 + 1];

long construct(int node, int l, int r) {
	if (l == r) {
		return tree[node] = seq[l];
	}

	int mid = (l + r) / 2;
	return tree[node] = construct(node * 2, l, mid) + construct(node * 2 + 1, mid + 1, r);
}

long find(int node, long l, long r, long start, long end) {
	if (l > end || r < start) {
		return 0;
	}

	if (start <= l && r <= end) {
		return tree[node];
	}

	int mid = (l + r) / 2;
	return find(node * 2, l, mid, start, end) + find(node * 2 + 1, mid + 1, r, start, end);
}

void update(int node, int l, int r, long index, long diff) {
	if (index < l || index > r) {
		return;
	}

	tree[node] += diff;
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, index, diff);
	update(node * 2 + 1, mid + 1, r, index, diff);
}

int main() {
	int n, m, k;
	std::scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		std::scanf("%ld", &seq[i]);
	}
	construct(1, 1, n);
	for (int i = 0; i < m + k; ++i) {
		long a, b, c;
		std::scanf("%ld %ld %ld", &a, &b, &c);
		if (a == 1) {
			update(1, 1, n, b, c - seq[b]);
			seq[b] = c;
		} else {
			std::printf("%ld\n", find(1, 1, n, b, c));
		}
	}
	return 0;
}