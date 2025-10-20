#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> strs;
    for (int num : numbers) {
        strs.push_back(to_string(num));
    }
    
    auto cmp = [](const string &a, const string &b) -> bool {
        return a + b < b + a;
    };
    
    sort(strs.begin(), strs.end(), cmp);
    
    string retval = accumulate(strs.rbegin(), strs.rend(), string());
    
    if (retval[0] == '0') {
        return "0";
    }
    
    return retval;
}