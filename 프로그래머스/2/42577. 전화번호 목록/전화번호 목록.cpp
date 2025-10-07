#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    for (const auto &n : phone_book) {
        for (int i = 1; i < n.size(); ++i) {
            s.insert(n.substr(0, i));
        }
    }
    for (const auto &n : phone_book) {
        if (s.find(n) != s.end()) return false;
    }
    return true;
}