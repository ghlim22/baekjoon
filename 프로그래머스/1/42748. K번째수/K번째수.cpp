#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const auto &command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        vector<int> v;
        for (int x = i - 1; x <= j - 1; ++x) {
            v.push_back(array[x]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[k - 1]);
    }
    
    return answer;
}