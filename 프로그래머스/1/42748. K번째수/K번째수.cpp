#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const auto &command : commands) {
        int i = command[0] - 1, j = command[1] - 1, k = command[2] - 1;
        auto v = array;
        sort(v.begin() + i, v.begin() + j + 1);
        answer.push_back(v[i + k]);
    }
    
    return answer;
}