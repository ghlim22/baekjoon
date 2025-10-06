#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void permutation_rep(vector<string> &dict, const string &s, string &p, int k) {
    if (p.size() == k) {
        dict.push_back(p);
        return;
    }
    for (char c : s) {
        p.push_back(c);
        permutation_rep(dict, s, p, k);
        p.pop_back();
    }
}

int solution(string word) {
    vector<string> dict;
    const string s{"AEIOU"};
    string p{""};
    for (int k = 1; k <= 5; ++k) {
       permutation_rep(dict, s, p, k);
    }
    sort(dict.begin(), dict.end());
    auto it = lower_bound(dict.begin(), dict.end(), word);
    return distance(dict.begin(), it) + 1;
}