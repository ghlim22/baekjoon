#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<string> split(const string &str) {
    int ind = str.find(' ');
    return {str.substr(0, ind), str.substr(ind + 1)};
}

vector<int> solution(vector<string> operations) {
    map<int, int> m;
    
    for (const string &str : operations) {
        auto vec = split(str);
        int num = stoi(vec[1]);
        if (vec[0] == "I") {
            m[num] += 1;
        } else if (!m.empty()) {
            int deleted;
            if (num == 1) {
                deleted = (--m.end())->first;
            } else {
                deleted = m.begin()->first;
            }
            m[deleted]--;
            if (m[deleted] == 0) {
                m.erase(deleted);
            }
        }
    }
    
    if (m.empty()) {
        return {0, 0};
    }
    
    return {(--m.end())->first, m.begin()->first};
}