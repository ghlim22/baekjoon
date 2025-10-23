#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

int main(void) {
  fastio;

  int n;
  std::cin >> n;

  std::vector<pii_t> v;
  for (int i = 0; i < n; ++i) {
	int a, b;
	std::cin >> a >> b;
	v.push_back({a, b});
  }

  std::sort(v.begin(), v.end());

  std::vector<int> lis; // b부분의 연결된 위치 삽입
  std::vector<int> idx; // 각 전선의 lis에서의 위치 삽입. idx[i]의 i은 v의 i와 같음.
  // lis에 속하지 않는 원소들이 제거해야 할 전선이다.

  lis.push_back(v[0].second);
  idx.push_back(0);

  for (int i = 1; i < n; ++i) {
	int pos = v[i].second;
	auto it = std::lower_bound(lis.begin(), lis.end(), pos);
	if (it == lis.end()) {
		idx.push_back(lis.size());
		lis.push_back(pos);
	} else {
		idx.push_back(std::distance(lis.begin(), it));
		*it = pos;
	}
  }

  std::vector<int> answer;
  int curr_lis_index = lis.size() - 1;
  for (int i = n - 1; i >= 0; --i) {
	if (idx[i] == curr_lis_index) { // LIS에 속하는 전선.
		curr_lis_index--;
	} else {
		answer.push_back(v[i].first);
	}
  }

  std::cout << answer.size() << '\n';
  for (auto it = answer.rbegin(); it != answer.rend(); ++it) {
	std::cout << *it << '\n';
  }

  return 0;
}