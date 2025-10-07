#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (const auto &cloth : clothes) {
        m[cloth[1]] += 1;
    }
    
    int answer = 1;
    for (const auto val : m) {
        answer *= (val.second + 1);
    }
    
    return answer - 1;
}