#include <cstdio>
#include <utility>
#include <vector>
#define MAX_SIZE (300000)
typedef std::pair<int, int> pii_t;
int connected[MAX_SIZE + 1];
int n;
int k;
void input()
{
	std::scanf("%d %d", &n, &k);
}
void solve()
{
	int global_edge_cnt = 0;
	for (int cur = 1; cur <= n && global_edge_cnt < n - 1; ++cur) {
		int adj_node;
		if (cur == 1) {
			adj_node = cur + 1;
		} else {
			adj_node = global_edge_cnt + 2;
		}
		for (; connected[cur] < k && adj_node <= n; ++adj_node) {
			if (connected[adj_node] > 0) {
				continue;
			}
			++global_edge_cnt;
			++connected[cur];
			++connected[adj_node];
			std::printf("%d %d\n", cur, adj_node);
		}
	}
}
int main(void)
{
	input();
	solve();

	return 0;
}