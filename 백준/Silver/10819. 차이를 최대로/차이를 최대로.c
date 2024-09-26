#include <stdio.h>

int arr[8];
int n;
int ans;

int abs(int n) { return (n < 0) ? -n : n; }

int sum_diff(int *a, int start, int end) {
  int res = 0;
  for (int i = start; i < end - 1; ++i) {
    res += abs(a[i] - a[i + 1]);
  }
  return res;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void permutations(int *a, int size, int idx) {
  if (idx == size - 1) {
    int sum = sum_diff(a, 0, size);
    if (sum > ans) {
      ans = sum;
    }
    return;
  }

  for (int i = idx; i < size; ++i) {
    swap(&a[i], &a[idx]);
    permutations(a, size, idx + 1);
    swap(&a[i], &a[idx]);
  }
}

int main(void) {
  /* INPUT */
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  permutations(arr, n, 0);
  printf("%d", ans);
  return 0;
}