#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool graph[101][101];
bool v[101];
int N;

int dfs(int node) {
   int count = 1;
   v[node] = true;
   for (int i = 1; i <= N; ++i)  {
       if (!v[i] && graph[node][i]) {
           count += dfs(i);
       }
   }
   v[node] = false;
   return count;
}

int solution(int n, vector<vector<int>> wires) {
    for (const auto &wire : wires) {
        const int a = wire[0];
        const int b = wire[1];
        graph[a][b] = true;
        graph[b][a] = true;
    }
    N = n;
    int answer = 100;
    for (const auto &wire : wires) {
        const int a = wire[0], b = wire[1];
        graph[a][b] = false; graph[b][a] = false;
        
        answer = min(answer, abs(dfs(a) - dfs(b)));
        
        graph[a][b] = true; graph[b][a] = true;
    }
    return answer;
}