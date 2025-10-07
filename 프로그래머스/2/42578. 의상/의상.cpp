#include <string>
#include <vector>
#include <map>

using namespace std;

int choose(int n, int k, int i, int sum, vector<int> &v) {
    if (k == 0) return sum;
    int ret = 0;
    for (int j = i; j <= n - k; ++j) {
        ret += choose(n, k - 1, j + 1, sum * v[j], v);
    }
    return ret;
}

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (const auto &c : clothes) {
        m[c[1]]++;
    }
    vector<int> v;
    for (const auto &value : m) {
        v.push_back(value.second);
    }
    int ret = 0;
    const int N = v.size();
    for (int k = 1; k <= N; ++k) {
        ret += choose(N, k, 0, 1, v);
    }
    return ret;
}