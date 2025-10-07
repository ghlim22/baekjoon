#include <functional>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<string, int> psi_t;

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genre_plays;
	for (int i = 0; i < genres.size(); ++i) {
		genre_plays[genres[i]] += plays[i];
	}
    
	priority_queue<psi_t, vector<psi_t>, function<bool(psi_t, psi_t)>> pq(
		[&genre_plays, &plays](const psi_t &p1, const psi_t &p2)->bool {
			if (p1.first != p2.first) 
				return genre_plays[p1.first] < genre_plays[p2.first];
			if (plays[p1.second] != plays[p2.second]) 
				return plays[p1.second] < plays[p2.second];
			return p1.second > p2.second;
		}
	);

	for (int i = 0; i < genres.size(); ++i) {
		pq.push({genres[i], i});
	}

	vector<int> answer;
	unordered_map<string, int> appeared;
	while (!pq.empty()) {
		const auto curr = pq.top();
		pq.pop();
		if (appeared[curr.first] >= 2) 
			continue;
		appeared[curr.first] += 1;
		answer.push_back(curr.second);
	}

	return answer;
}