#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int num : scoville) {
        pq.push(num);
    }
    
    while (pq.size() >= 2) {
        int last = pq.top(); pq.pop();
        if (last >= K) break;
        int second_last = pq.top(); pq.pop();
        pq.push(last + second_last * 2);
        answer++;
    }
    
    if (pq.top() < K) {
        return -1;
    }
    
    return answer;
}