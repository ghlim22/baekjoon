#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (auto it = lost.begin(); it != lost.end();) {
        auto it2 = std::find(reserve.begin(), reserve.end(), *it);
        if (it2 != reserve.end()) {
            it = lost.erase(it);
            reserve.erase(it2);
        } else {
            ++it;
        }
    }
    
    int answer = n - lost.size();
    for (auto it = lost.begin(); it != lost.end(); ++it) {
        int val = *it;
        auto it2 = std::find_if(reserve.begin(), reserve.end(), [&val](const auto &x) { 
            return std::abs(x - val) <= 1;
        });
        if (it2 != reserve.end()) {
            reserve.erase(it2);
            answer++;
        }
    }
    return answer;
}