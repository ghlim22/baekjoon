#include <stdio.h>

#define MAX (8)

int input[MAX];
int seq[MAX];
// int visited[MAX];
int n;
int m;

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *a, int low, int high) {
  if (low >= high) {
    return;
  }

  int i = low;
  int j = low;
  int *pivot = &a[high];

  for (; j < high; ++j) {
    if (a[j] < *pivot) {
      swap(&a[i++], &a[j]);
    }
  }
  swap(&a[i], pivot);

  sort(a, low, i - 1);
  sort(a, i + 1, high);
}

void solve(int len) {
  if (len == m) {
    /* Print */
    for (int i = 0; i < len; ++i) {
      printf("%d ", seq[i]);
    }
    printf("\n");
    return;
  }

  int prev = 0;
  for (int i = 0; i < n; ++i) {
    // if (visited[i])
    //   continue;
    if (input[i] == prev) {
      continue;
    }
    seq[len] = input[i];
    prev = input[i];
    // visited[i] = 1;
    solve(len + 1);
    // visited[i] = 0;
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &input[i]);
  }
  sort(input, 0, n - 1);
  solve(0);
  return 0;
}