#include <stdio.h>

int main(void) {
  int n, k;
  char string[51];

  scanf("%d %d", &n, &k);

  int i;
  for (i = 0; i < n; ++i) {
    if (i * (n - i) >= k) {
      break;
    }
  }

  if (i == n) {
    printf("-1\n");
    return 0;
  }

  int r = i * (n - i);
  int j;

  if (k == 0) {
    j = n - 1;
  } else {
    for (j = i - 1; r > k && j < n; ++j) {
      r--;
    }
  }

  for (int k = 0; k < n; ++k) {
    if (k < i - 1) {
      string[k] = 'A';
    } else if (k == j) {
      string[k] = 'A';
    } else {
      string[k] = 'B';
    }
  }

  string[n] = '\0';
  
  printf("%s\n", string);

  return 0;
}