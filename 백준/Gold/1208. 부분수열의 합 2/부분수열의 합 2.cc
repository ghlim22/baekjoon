#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void sum_subset(int cur, int end, T sum, std::vector<T> &res,
                const std::vector<T> &set) {
  if (cur >= end) {
    res.push_back(sum);
    return;
  }
  sum_subset(cur + 1, end, sum, res, set);
  sum_subset(cur + 1, end, sum + set[cur], res, set);
}

int main(void) {
  long N, S, cnt = 0;
  std::vector<int> set, left_sum, right_sum;

  std::cin >> N >> S;
  set.resize(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> set[i];
  }

  // Meet in the middle
  sum_subset<int>(0, N / 2, 0, left_sum, set);
  sum_subset<int>(N / 2, N, 0, right_sum, set);

  std::sort(left_sum.begin(), left_sum.end());
  std::sort(right_sum.begin(), right_sum.end());

  for (int l : left_sum) {
    auto lower = std::lower_bound(right_sum.begin(), right_sum.end(), S - l);
    if (lower == right_sum.end())
      continue;
    auto upper = std::upper_bound(right_sum.begin(), right_sum.end(), S - l);
    cnt += upper - lower;
  }

  cnt -= (S == 0); // The size of a subset must be > 0;

  std::cout << cnt << std::endl;

  return 0;
}
