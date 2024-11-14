#include <algorithm>
#include <iostream>

#define MAX (100)

struct sticker {
  int r;
  int c;
};

int H;
int W;
int N;
sticker INPUT[MAX];

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> H >> W >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> INPUT[i].r >> INPUT[i].c;
  }

  int answer = 0;
  sticker arr[4];
  for (int i = 0; i < N; ++i) {
    arr[0] = INPUT[i];
    arr[1] = sticker{.r = INPUT[i].c, .c = INPUT[i].r};
    for (int j = 0; j < N; ++j) {
      if (i == j)
        continue;
      arr[2] = INPUT[j];
      arr[3] = {.r = INPUT[j].c, .c = INPUT[j].r};
      for (int k = 0; k < 2; ++k) {
        for (int l = 2; l < 4; ++l) {
          if (std::max(arr[k].r, arr[l].r) <= H && arr[k].c + arr[l].c <= W) {
            answer =
                std::max(answer, arr[k].r * arr[k].c + arr[l].r * arr[l].c);
          }
          if (std::max(arr[k].c, arr[l].c) <= W && arr[k].r + arr[l].r <= H) {
            answer =
                std::max(answer, arr[k].r * arr[k].c + arr[l].r * arr[l].c);
          }
        }
      }
    }
  }

  std::cout << answer;

  return 0;
}