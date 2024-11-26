#include <iostream>
#include <climits>
#include <algorithm>

int N;
int M;
int cnt[4001];
bool graph[4001][4001];


int main(void) {
    std::cin >> N >> M;

    for (int i  = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        cnt[a]++;
        cnt[b]++;
    }

    int answer = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (!graph[i][j])
                continue;
            for (int k = j + 1; k <= N; ++k) {
                if (!graph[i][k] || !graph[j][k])
                    continue;
                answer = std::min(cnt[i] + cnt[j] + cnt[k] - 6, answer);
            }
        }
    }

    if (answer == INT_MAX)
        answer = -1;

    std::cout << answer;

    return 0;
}