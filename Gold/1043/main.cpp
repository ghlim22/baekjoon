#include <cstdio>
#include <queue>
#define MAX_SIZE (50)

bool people[MAX_SIZE + 1];
bool party_list[MAX_SIZE + 1][MAX_SIZE + 1]; /* party_list[i][j] == true -> i번
                                                파티에 j번 사람이 참석했음. */
bool visited[MAX_SIZE + 1];

int main(void)
{
    int n;
    int m;
    int cnt;
    int input;
    int truth_party = 0;
    std::queue<int> q;

    std::scanf("%d %d", &n, &m);
    std::scanf("%d", &cnt);
    while (cnt--) {
        std::scanf("%d", &input);
        q.push(input);
    }
    for (int i = 1; i <= m; ++i) {
        std::scanf("%d", &cnt);
        for (int j = 1; j <= cnt; ++j) {
            std::scanf("%d", &input);
            party_list[i][input] = true;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= m; ++i) {
            if (!visited[i] && party_list[i][cur]) {
                truth_party++;
                visited[i] = true;
                for (int j = 1; j <= n; ++j) {
                    if (cur != j && party_list[i][j]) {
                        q.push(j);
                    }
                }
            }
        }
    }
    std::printf("%d\n", m - truth_party);
    return 0;
}