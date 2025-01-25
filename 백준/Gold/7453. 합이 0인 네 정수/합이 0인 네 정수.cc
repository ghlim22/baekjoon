#include <algorithm>
#include <cstdio>
#include <vector>

#define LEN 4000

int input[4][LEN];

int main(void) {
  int N;
  long cnt = 0;
  std::vector<long> sumsAB, sumsCD;

  std::scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    std::scanf("%d %d %d %d", &input[0][i], &input[1][i], &input[2][i],
               &input[3][i]);
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      sumsAB.push_back(input[0][i] + input[1][j]);
      sumsCD.push_back(input[2][i] + input[3][j]);
    }
  }

  std::sort(sumsAB.begin(), sumsAB.end());
  std::sort(sumsCD.begin(), sumsCD.end());

  for (int i = 0, j = N * N - 1; i < N * N && j >= 0;) {
    long sum = sumsAB[i] + sumsCD[j];
    if (sum < 0) {
      i++;
    } else if (sum > 0) {
      j--;
    } else {
      long left = 1;
      long right = 1;
      while (i + left < N * N && sumsAB[i] == sumsAB[i + left]) {
        left++;
      }
      while (j - right >= 0 && sumsCD[j] == sumsCD[j - right]) {
        right++;
      }
      cnt += left * right;
      i += left;
      j -= right;
    }
  }
  std::printf("%ld\n", cnt);

  return 0;
}
