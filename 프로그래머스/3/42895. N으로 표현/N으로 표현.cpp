#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> S[9];

void init(int N) {
    int digit = N;
    for (int i = 1; i <= 8; ++i) {
        S[i].insert(N);
        N = N * 10 + digit;
    }
}

int solution(int N, int number) {
    init(N);
    for (int i = 2; i <= 8; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int x : S[i - j]) {
                for (int y : S[j]) {
                    S[i].insert(x + y);
                    S[i].insert(x - y);
                    S[i].insert(x * y);
                    if (y != 0)
                        S[i].insert(x / y);
                }
            }
        }
    }
    
    for (int i = 1; i <= 8; ++i) {
        if (S[i].find(number) != S[i].end())
            return i;
    }
    
    return -1;
}