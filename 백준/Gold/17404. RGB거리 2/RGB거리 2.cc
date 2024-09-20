#include <limits.h>
#include <stdio.h>

#define R (0)
#define G (1)
#define B (2)
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
  int answer = INT_MAX;

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d %d", &input[i][R], &input[i][G], &input[i][B]);

  for (int i = 0; i < 3; ++i) {
    /* Select color to paint the first house */
    for (int j = 0; j < 3; ++j) {
      if (i == j)
        cache[1][j] = input[1][j];
      else
        cache[1][j] = INT_MAX;
    }
    /* Caculate the minimum cost for each path */
    for (int j = 2; j <= n; ++j) {
      cache[j][R] = input[j][R] + min(cache[j - 1][B], cache[j - 1][G]);
      cache[j][B] = input[j][B] + min(cache[j - 1][R], cache[j - 1][G]);
      cache[j][G] = input[j][G] + min(cache[j - 1][R], cache[j - 1][B]);
    }
    /* Get the total minimum cost */
    /* the color of the first house != the color of the last house */
    for (int j = 0; j < 3; ++j) {
      if (i != j)
        answer = min(answer, cache[n][j]);
    }
  }

  printf("%d\n", answer);

  return 0;
}
