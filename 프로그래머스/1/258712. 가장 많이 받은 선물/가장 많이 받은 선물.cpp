#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, map<string, int>> graph;
    map<string, int> gift_score;
    for (const string &s : gifts) {
        int ind = s.find(' ');
        auto from = s.substr(0, ind);
        auto to = s.substr(ind+1);
        graph[from][to] += 1;
        gift_score[from]++;
        gift_score[to]--;
    }
    
    for (const string &me : friends) {
        int count = 0;
        for (const string &other : friends) {
            if (me == other) continue;
            int give_count = graph[me][other];
            int receive_count = graph[other][me];
            if (give_count != receive_count) {
                if (give_count > receive_count) count++;
            } else {
                if (gift_score[me] > gift_score[other]) count++;
            }
        }
        answer = max(answer, count);
    }
    
    return answer;
}