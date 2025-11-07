#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;

int main() {
	long n, d, h, o;
	scanf("%ld", &n);

	std::vector<pii> points;
	for (int i = 0; i < n; ++i) {
		scanf("%ld %ld", &h, &o);
		points.push_back({h, i});
		points.push_back({o, i});
	}
	scanf("%ld", &d);
	std::sort(points.begin(), points.end());

	std::vector<int> counts(n);
	int answer = 0;
	int count = 0;

	for (int left = 0, right = 0; left < 2 * n && right < 2 * n; ++left) {
		right = std::max(left, right);
		auto [start_point, start_index] = points[left];
		long end_point = d + start_point;

		while (right < 2 * n && points[right].first <= end_point) {
			int index = points[right].second;
			counts[index]++;
			if (counts[index] == 2) {
				count++;
			}
			right++;
		}

		answer = std::max(answer, count);

		if (counts[start_index] == 2) {
			count--;
		}
		counts[start_index]--;
	}

	printf("%d\n", answer);

	return 0;
}