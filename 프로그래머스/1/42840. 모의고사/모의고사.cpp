#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> one = {
        1, 2, 3, 4, 5
    };
    vector<int> two = {
        2, 1, 2, 3, 2, 4, 2, 5
    };
    vector<int> three = {
        3, 3, 1, 1, 2, 2, 4, 4, 5, 5
    };
    
    int one_answer = 0, two_answer = 0, three_answer = 0;
    for (int i = 0; i < answers.size(); ++i) {
        if (one[i % one.size()] == answers[i])
            one_answer += 1;
        if (two[i % two.size()] == answers[i])
            two_answer += 1;
        if (three[i % three.size()] == answers[i])
            three_answer += 1;
    }
    vector<int> answer;
    if (one_answer >= two_answer && one_answer >= three_answer) {
       answer.push_back(1);
    }
    if (two_answer >= one_answer && two_answer >= three_answer) {
       answer.push_back(2);
    }
    if (three_answer >= one_answer && three_answer >= two_answer) {
       answer.push_back(3);
    }
    return answer;
}