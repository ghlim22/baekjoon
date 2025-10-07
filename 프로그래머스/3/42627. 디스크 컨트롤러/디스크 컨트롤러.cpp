#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// processing time, time requested, index
typedef pair<pair<int, int>, int> job;

int solution(vector<vector<int>> jobs) {
    priority_queue<job, vector<job>, function<bool(job, job)>> job_list(
        [](const job& a, const job& b) -> bool {
            return a.first.second > b.first.second;
        }
    );
    for (int i = 0; i < jobs.size(); ++i) {
        job_list.push({{jobs[i][1], jobs[i][0]}, i});
    }
    
    priority_queue<job, vector<job>, greater<job>> wating_queue;
    int time = 0;
    int answer = 0;
    for (;;) {
        if (wating_queue.empty()) {
            if (job_list.empty())
                break;
            if (time < job_list.top().first.second) {
                time = job_list.top().first.second;
            }
        }
        
        while (!job_list.empty() && time >= job_list.top().first.second) {
            wating_queue.push(job_list.top());
            job_list.pop();
        }
        
        job curr = wating_queue.top();
        wating_queue.pop();
        time += curr.first.first;
        answer += (time - curr.first.second);
    }
    return answer / jobs.size();
}