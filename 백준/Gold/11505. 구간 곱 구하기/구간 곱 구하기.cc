#include <cstdio>
#define SIZE 1000000
#define MODULUS 1000000007

int seq[SIZE + 1];
int tree[4 * SIZE + 1];

long construct(int node, int start, int end)
{
	if (start == end) {
		return tree[node] = seq[start];
	}

	int mid = (start + end) / 2;
	long leftval = construct(node * 2, start, mid);
	long rightval = construct(node * 2 + 1, mid + 1, end);
	return tree[node] = (leftval * rightval) % MODULUS;
}

long find(int node, int start, int end, int target_start, int target_end)
{
	if (target_start > end || target_end < start) {
		return 1;
	}
	if (target_start <= start && end <= target_end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	long leftval = find(node * 2, start, mid, target_start, target_end);
	long rightval = find(node * 2 + 1, mid + 1, end, target_start, target_end);
	return (leftval * rightval) % MODULUS;
}

long update(int node, int start, int end, int index, long newval)
{
	if (index < start || index > end) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] = newval;
	}

	int mid = (start + end) / 2;
	long leftval = update(node * 2, start, mid, index, newval);
	long rightval = update(node * 2 + 1, mid + 1, end, index, newval);
	return tree[node] = (leftval * rightval) % MODULUS;
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &seq[i]);
	}
	construct(1, 1, n);
	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			update(1, 1, n, b, c);
		} else {
			printf("%ld\n", find(1, 1, n, b, c));
		} 	
	}
	return 0;
}