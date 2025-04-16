#include <stdio.h>

int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

int get_length(int n) {
  int d = 1;
  int l = 1;
  int len = 0;
  while (n >= d) {
    len += (min(n, d * 10 - 1) - d + 1) * l;
    d *= 10;
    l++;
  }
  return len;
}

int get_digit(int num, int k) {
  char str[10];
  snprintf(str, 10, "%d", num);
  return str[k] - '0';
}

int solve(int n, int k) {
  int lo = 1;
  int hi = n;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int lower = get_length(mid - 1);
    int upper = get_length(mid);
    if (k > lower && k <= upper) {
      return get_digit(mid, k - lower - 1);
    }
    if (k < upper) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return -1;
}

int main(void) {
  int n, k;

  scanf("%d %d", &n, &k);
  printf("%d\n", solve(n, k));

  return 0;
}