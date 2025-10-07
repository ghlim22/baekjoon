#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> genre_plays;
    map<string, vector<pair<int, int>>> songs;
    
    for (int i = 0; i < genres.size(); ++i) {
        const auto &genre = genres[i];
        const auto &song = std::make_pair(i, plays[i]);
        songs[genre].push_back(song);
        genre_plays[genre] += plays[i];
    }
    
    vector<pair<string, int>> genre_plays_vec(genre_plays.begin(), genre_plays.end());
    sort(genre_plays_vec.begin(), genre_plays_vec.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    
    for (auto &val : songs) {
        auto &vec = val.second;
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return (a.second == b.second) ? (a.first < b.first) : (a.second > b.second);
        });
    }
    
    vector<int> answer;
    for (const auto &val1 : genre_plays_vec) {
        const string &genre = val1.first;
        const auto &vec = songs[genre];
        for (int i = 0; i < vec.size(); ++i) {
            if (i >= 2) break;
            answer.push_back(vec[i].first);
        }
    }
    
    return answer;
}