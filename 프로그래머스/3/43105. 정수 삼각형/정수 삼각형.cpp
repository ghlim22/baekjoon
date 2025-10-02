#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            int maximum = 0;
            if (j == 0) {
                maximum = triangle[i - 1].front();
            } else if (j == triangle[i].size() - 1) {
                maximum = triangle[i - 1].back();
            } else {
                maximum = max(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i][j] += maximum;
        }
    }
    
    int answer = 0;
    for (int n : triangle.back()) {
        answer = max(answer, n);
    }
    
    return answer;
}