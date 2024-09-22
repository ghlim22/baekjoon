#include <stdio.h>

int gcd(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }

  while (b > 0) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {
  int t;
  int m;
  int n;
  int x;
  int y;

  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &m, &n, &x, &y);
    /* The last year of calendar is LCM(m, n). */
    /* Let l is the last year of the calendar.
     * (l - m) % m = 0
     * (l - n) % n = 0
     * 정리하면,
     * l % m = 0 and l % n = 0
     * The smallest l that meets the above condition is LCM(m, n).
     */
    /* <m : n> <x : y>
     * x` = x + 1 if x <  m, 1 otherwise.
     * y` = y + 1 if y < n, 1 otherwise.
     * 어떤 해 k가 카잉 달력으로 표현 가능하다면,
     * (k - x) % m = 0 and
     * (k - y) % n = 0 을 만족한다.
     * k를 1씩 증가시키면서 확인하면 시간 내에 문제를 풀 수 없다.
     * k = m * i + x (i는 i >= 0인 정수)라 하면 k가 n과 y의 조건을 만족하는 지
     * 확인하면 된다.  *
     */
    const int LIMIT = lcm(m, n);
    int answer = -1;
    int year;
    for (year = x; year <= LIMIT; year += m) {
      if ((year - y) % n == 0) {
        answer = year;
        break;
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}
