#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int d[1000000][2];

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    
    // case 1. house0 selected
    d[0][0] = money[0];
    d[0][1] = money[0];
    d[1][0] = money[0];
    d[1][1] = money[0];
    for (int i = 2; i < N; ++i) {
        d[i][0] = d[i-1][1] + money[i];
        d[i][1] = max(d[i-1][0], d[i-1][1]);
    }
    answer = d[N-1][1];
    
    // case 2. house1 not selected
    d[1][0] = money[1];
    d[1][1] = 0;
    for (int i = 2; i < N; ++i) {
        d[i][0] = d[i-1][1] + money[i];
        d[i][1] = max(d[i-1][0], d[i-1][1]);
    }
    answer = max(answer, d[N-1][0]);
    answer = max(answer, d[N-1][1]);
     
    return answer; 
}