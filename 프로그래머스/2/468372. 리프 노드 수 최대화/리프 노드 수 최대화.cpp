#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int D;
int S;

int f(int current, int dist, long split) {
    if (split > S || dist > D) {
        return 0;
    }
    int leaf = current;
    for (int i = 2; i <= 3; ++i) {
        if (i * split > S) continue;
        int d = min(D - dist, current);
        int next = d * i;
        leaf = max(leaf, (current-d) + f(next, dist + d, split * i));
    }
    return leaf;
}

int solution(int dist_limit, int split_limit) {
    D = dist_limit;
    S = split_limit;
    return f(1, 0, 1);
}