#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for (const auto &name : completion) {
        m[name]++;
    }
    
    for (const auto &name: participant) {
        if (m.count(name) == 0) {
            return name;
        }
        auto it = m.find(name);
        it->second -= 1;
        if (it->second == 0) {
            m.erase(it);
        }
    }
    return "";
}