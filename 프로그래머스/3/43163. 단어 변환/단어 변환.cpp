#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    set<string> words_set;
    for (auto &word : words) {
        words_set.insert(word);
    }
    
    set<string> v;
    queue<string> q;
    
    v.insert(begin);
    q.push(begin);
    
    for (int cnt = 0; !q.empty(); ++cnt) {
        int len = q.size();
        while (len--) {
            string curr = q.front();
            q.pop();
            
            if (curr == target) {
                return cnt;
            }
            
            for (int i = 0; i < curr.size(); ++i) {
               char original = curr[i];
               for (char modified = 'a'; modified <= 'z'; ++modified) {
                   curr[i] = modified;
                   if (words_set.find(curr) == words_set.end()) {
                      continue; 
                   }
                   if (v.find(curr) != v.end()) {
                       continue;
                   }
                   v.insert(curr);
                   q.push(curr);
               }
               curr[i] = original;
            }
        }
    }
   
    return 0;
}