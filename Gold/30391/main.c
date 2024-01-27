#include <stdio.h>

#define MAX_SIZE (300000)

int edge_cnt[MAX_SIZE + 1]; /* The count of edges attached to each vertex */
int n;
int k;

void input() { scanf("%d %d", &n, &k); }

void solve()
{
    int adj_node;
    int global_edge_cnt = 0;

    for (int cur_node = 1; cur_node <= n && global_edge_cnt < n - 1;
         ++cur_node) {
        if (cur_node == 1) {
            adj_node = cur_node + 1;
        } else {
            /* Skip vertices that are already connected */
            /* n - 1 edges connect n vertices & index starts from 1 */
            adj_node = global_edge_cnt + 2;
        }
        for (; edge_cnt[cur_node] < k && adj_node <= n; ++adj_node) {
            ++global_edge_cnt;
            ++edge_cnt[cur_node];
            ++edge_cnt[adj_node];
            printf("%d %d\n", cur_node, adj_node);
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}