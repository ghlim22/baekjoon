#include <string>
#include <vector>

using namespace std;

vector<int> G[1000001];

void construct(vector<int> &nodes, vector<vector<int>> &edges) {
    for (auto &edge: edges) {
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);
    }
}

bool check(int node, int (*f)(int, int), int prev) {
    for (int adj : G[node]) {
        if (adj == prev) 
            continue;
        if (!f(adj, node)) 
            return 0;
    }
    return 1;
}


int find(int node, int prev) {
    int children = G[node].size() - (prev != -1 ? 1 : 0);
    if (node % 2 == 0 && children % 2 != 0) {
        return 0;
    } 
    if (node % 2 != 0 && children % 2 == 0) {
       return 0; 
    }
    
    return check(node, find, prev);  
}

int revfind(int node, int prev) {
    int children = G[node].size() - (prev != -1 ? 1 : 0);
    if (node % 2 == 0 && children % 2 == 0) {
        return 0;
    } 
    if (node % 2 != 0 && children % 2 != 0) {
       return 0; 
    }
    
    return check(node, revfind, prev);  
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    
    construct(nodes, edges);
    
    for (int node : nodes) {
        answer[0] += find(node, -1);
        answer[1] += revfind(node, -1);
    }
    
    return answer;
}