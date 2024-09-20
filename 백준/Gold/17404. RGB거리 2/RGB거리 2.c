#include <limits.h>
#include <stdio.h>

#define RED (0)
#define GREEN (1)
#define BLUE (2)
#define MAX (1000)

/* cache[i][j][k]
 * i: house no.
 * j: color of house i
 */
unsigned int cache[MAX + 1][3];

int input[MAX + 1][3];

unsigned int min(unsigned int a, unsigned int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int main(void) {
  int n;
  int ans = INT_MAX;

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d %d", &input[i][RED], &input[i][GREEN], &input[i][BLUE]);

  /* Select red for the first house. */
  cache[1][RED] = input[1][RED];
  cache[1][BLUE] = INT_MAX;
  cache[1][GREEN] = INT_MAX;
  for (int i = 2; i <= n; ++i) {
    cache[i][RED] =
        input[i][RED] + min(cache[i - 1][BLUE], cache[i - 1][GREEN]);
    cache[i][BLUE] =
        input[i][BLUE] + min(cache[i - 1][RED], cache[i - 1][GREEN]);
    cache[i][GREEN] =
        input[i][GREEN] + min(cache[i - 1][RED], cache[i - 1][BLUE]);
  }
  ans = min(cache[n][BLUE], cache[n][GREEN]);

  /* Select blue for the first house. */
  cache[1][RED] = INT_MAX;
  cache[1][BLUE] = input[1][BLUE];
  cache[1][GREEN] = INT_MAX;
  for (int i = 2; i <= n; ++i) {
    cache[i][RED] =
        input[i][RED] + min(cache[i - 1][BLUE], cache[i - 1][GREEN]);
    cache[i][BLUE] =
        input[i][BLUE] + min(cache[i - 1][RED], cache[i - 1][GREEN]);
    cache[i][GREEN] =
        input[i][GREEN] + min(cache[i - 1][RED], cache[i - 1][BLUE]);
  }
  ans = min(ans, min(cache[n][RED], cache[n][GREEN]));

  /* Select green for the first house. */
  cache[1][RED] = INT_MAX;
  cache[1][BLUE] = INT_MAX;
  cache[1][GREEN] = input[1][GREEN];
  for (int i = 2; i <= n; ++i) {
    cache[i][RED] =
        input[i][RED] + min(cache[i - 1][BLUE], cache[i - 1][GREEN]);
    cache[i][BLUE] =
        input[i][BLUE] + min(cache[i - 1][RED], cache[i - 1][GREEN]);
    cache[i][GREEN] =
        input[i][GREEN] + min(cache[i - 1][RED], cache[i - 1][BLUE]);
  }
  ans = min(ans, min(cache[n][RED], cache[n][BLUE]));

  printf("%d\n", ans);

  return 0;
}
