#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>> &sizes, int w, int h) {
	for (auto &size : sizes) {
        if (!((size[0] <= w && size[1] <= h) || (size[1] <= w && size[0] <= h))) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<int>> sizes) {
    int answer = 1000 * 1000;
    for (int w = 1; w <= 1000; ++w) {
        for (int h = 1; h <= 1000; ++h) {
            if (check(sizes, w, h)) {
                answer = min(answer, w * h);
            }
        }
    }
    
    return answer;
}