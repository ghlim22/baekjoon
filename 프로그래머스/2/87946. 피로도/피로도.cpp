#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int f(int k, vector<vector<int>> &dungeons, vector<bool> &v) {
    int count = 0;
    for (int i = 0; i < dungeons.size(); ++i) {
        if (!v[i] && k >= dungeons[i][0]) {
            v[i] = true;
            count = max(count, 1 + f(k - dungeons[i][1], dungeons, v));
            v[i] = false;
        }
    }
    return count;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> v(dungeons.size());
    return f(k, dungeons, v);
}