#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for (int h = citations.back(); h >= 0; --h) {
        auto lo = lower_bound(citations.begin(), citations.end(), h);
        int geq = distance(lo, citations.end());
        
        if (geq >= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}