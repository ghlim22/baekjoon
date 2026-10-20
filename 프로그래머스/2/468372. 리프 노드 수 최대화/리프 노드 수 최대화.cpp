#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long pow(long x, long y) {
    long res = 1;
    while (y--) {
        res *= x;
    }
    return res;
}

int solution(int dist_limit, int split_limit) {
    long answer = 0;
    
    long DL = dist_limit;
    long SL = split_limit;
    
    // i: 2-분배 블록 층 수
    for (int i = 0;; ++i) {
        if (pow(2, i) > SL) break;
        
        long d2 = min(DL, pow(2, i) - 1);
        long remain = DL - d2;
        long leaf = 1 + d2;
        // j: 3-분배 블록 층 수
        for (int j = 1;;++j) {
            if (remain == 0) break;
            if (pow(2, i) * pow(3, j) > SL) break;
            long d3 = min(remain, leaf);
            leaf += 2 * d3;
            remain -= d3;
        }
        answer = max(answer, leaf);
    }
    
    return (int)answer;
}