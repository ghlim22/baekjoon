#include <stdio.h>
#include <string.h>

int a[100000];
int b[100000];
int c[100000];

void push_switch(int array[], int i, int n) {
  if (i > 0) {
    array[i - 1] ^= 1;
  }
  if (i < n) {
    array[i + 1] ^= 1;
  }
  array[i] ^= 1;
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%1d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%1d", &b[i]);
  memmove(c, a, sizeof(int) * n);

  // case 1
  // no use of switch 1
  int count = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] != b[i - 1]) {
      push_switch(a, i, n);
      count++;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      count = -1;
      break;
    }
  }

  if (count != -1) {
    printf("%d\n", count);
    return 0;
  }

  // case 2
  // use switch 1
  count = 1;
  push_switch(c, 0, n);
  for (int i = 1; i < n; ++i) {
    if (c[i - 1] != b[i - 1]) {
      push_switch(c, i, n);
      count++;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] != b[i]) {
      count = -1;
      break;
    }
  }

  printf("%d\n", count);

  return 0;
}
