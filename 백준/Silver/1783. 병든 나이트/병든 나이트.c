#include <stdio.h>

const int dy[4] = {2, -2, 1, -1};
const int dx[4] = {1, 1, 2, 2};

int not_less_than_four(int n, int m) {
  if (n < 3 || m < 5) {
    return 1;
  }
  /*
  처음에 2번, 3번 연산을 수행한다. 방문점 수 = 3 , (y = 0, x = 4)
  그리고 체스판의 오른쪽 끝에 도달할 때까지 1번 연산과 4번 연산을 번갈아
  수행한다. 그러면 x = 4 이후의 모든 열에 대해서 한 번씩 방문하게 된다.
  */
  return (m - 2); /* 3 + (m - 4 - 1) */
}

int less_than_four(int n, int m) {
  int counter = 1;
  int possible = 1;
  int y = 0;
  int x = 0;

  while (possible && counter < 4) {
    possible = 0;
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (!(ny >= 0 && ny < n && nx >= 0 && nx < m)) {
        continue;
      }
      possible = 1;
      counter++;
      y = ny;
      x = nx;
      break;
    }
  }

  return counter;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int main(void) {
  int n, m;

  scanf("%d %d", &n, &m);
  int counter = max(less_than_four(n, m), not_less_than_four(n, m));
  printf("%d\n", counter);

  return 0;
}