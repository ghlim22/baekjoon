#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

map<string, vector<pair<string, bool>>> graph;

bool f(vector<string> &path, int n) {
    if (n == 0) {
        return true;
    }
    string from = path.back();
    for (auto &ticket : graph[from]) {
        if (!ticket.second) continue;
        path.push_back(ticket.first);
        ticket.second = false;
        if (f(path, n - 1)) {
            return true;
        }
        path.pop_back();
        ticket.second = true;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {    
    for (auto &ticket : tickets) {
        graph[ticket[0]].push_back({ticket[1], true});
    }
    for (auto &it : graph) {
        sort(it.second.begin(), it.second.end());
    }
    vector<string> answer = {"ICN"};
    f(answer, tickets.size());
    
    return answer;
}