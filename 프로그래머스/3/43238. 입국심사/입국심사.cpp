#include <string>
#include <vector>

using namespace std;

long long check(const vector<int> &times, long long total) {
    long long cnt = 0;
    for (int time : times) {
        cnt += (total / time);
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    long long right = n * 1000000000L;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = check(times, mid);
        if (cnt >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}