#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool inSpoiler(vector<bool> &ranges, int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (ranges[i]) return true;
    }
    return false;
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    
    vector<bool> ranges(message.size());
    for (auto &v: spoiler_ranges) {
        for (int i = v[0]; i <= v[1]; ++i)
            ranges[i] = true;
    }
    
    set<string> swords;
    set<string> nswords;
    for (long i = 0; i < message.size(); ++i) {
        long j = min(message.find(' ', i), message.size());
        long start = i; long end = j - 1;
        string w = message.substr(start, end - start + 1);
        if (inSpoiler(ranges, start, end)) {
            swords.insert(w);
        } else {
            nswords.insert(w);
        }
        i = j;
    }
    
    int ans = 0;
    for (auto &w : swords) {
        if (nswords.find(w) == nswords.end()) {
            cout<<w<<'\n';
            ans++;
        }
    }
    
    return ans;
}

