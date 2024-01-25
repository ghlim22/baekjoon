#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <utility>

#define MAX_SIZE (100000)

typedef std::pair<int, int> pii_t;

int n = 0;
int k = 0;
int result = 0;
int time_arr[MAX_SIZE + 1];

void input() { std::cin >> n >> k; }

void solve()
{
    int cur_node;
    std::queue<int> q;

    std::memset(time_arr, -1, sizeof(time_arr));
	time_arr[n] = 0;
    q.push(n);
    do {
        cur_node = q.front();
        q.pop();

        int next_node[3] = {cur_node * 2, cur_node - 1, cur_node + 1};
        for (int i = 0; i < 3; ++i) {
            if (!(next_node[i] >= 0 && next_node[i] <= MAX_SIZE)) {
                continue;
            }
            int next_time =
                (i == 0) ? (time_arr[cur_node]) : (time_arr[cur_node] + 1);
            if (time_arr[next_node[i]] == -1 ||
                time_arr[next_node[i]] > next_time) {
                time_arr[next_node[i]] = next_time;
                q.push(next_node[i]);
            }
        }
    } while (!q.empty() && cur_node != k);

    std::cout << time_arr[k] << std::endl;
}

int main(void)
{
    input();
    solve();

    return 0;
}