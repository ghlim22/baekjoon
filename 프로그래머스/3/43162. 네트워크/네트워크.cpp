#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> V(200, false);

void bfs(int n, vector<vector<int>> computers, int node) {
   std::queue<int> q;
    q.push(node);
    V[node] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int j = 0; j < n; ++j) {
            if (V[j]) 
                continue;
            if (computers[curr][j] == 0)
                continue;
            V[j] = true;
            q.push(j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (!V[i]) {
            answer += 1;
            bfs(n, computers, i);
        }
    }
    return answer;
}