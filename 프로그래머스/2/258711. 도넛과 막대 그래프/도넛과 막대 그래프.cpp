#include <map>
#include <string>
#include <vector>

using namespace std;

#define SIZE 1000000

int in[SIZE + 1];
int out[SIZE + 1];
bool visited[SIZE + 1];
map<int, vector<int>> graph;

void dfs(int node) {
   visited[node] = true;
   for (int out : graph[node]) {
       if (!visited[out]) {
           visited[out] = true;
           dfs(node);
       }
   }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    for (const auto &edge : edges) {
        const int from = edge[0];
        const int to = edge[1];
        if (graph.find(from) == graph.end()) graph.insert({from, vector<int>()});
        if (graph.find(to) == graph.end()) graph.insert({to, vector<int>()});
        graph[from].push_back(to);
        in[to]++;
        out[from]++;
    }

	int center = 0;
	for (const auto &val : graph) {
        int node = val.first;
        if (in[node] == 0 && out[node] >= 2) {
            center = node;
            visited[center] = true;
            for (int to : val.second) {
                in[to]--;
            }
            break;
        }
    }
    answer[0] = center;
	

    for (const auto &val : graph) {
        int node = val.first;
        if (visited[node]) continue;
        if (in[node] == 0) {
            answer[2]++; // 막대
            dfs(node);
        } else if (in[node] == 2 && out[node] == 2) {
            answer[3]++; // 8자
            dfs(node);
        }
    }

    answer[1] = out[center] - answer[2] - answer[3];
    
    return answer;
}