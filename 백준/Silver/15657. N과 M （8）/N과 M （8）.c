#include <stdio.h>

#define MAX (8)

int input[MAX];
int seq[MAX];
// int visited[MAX];
int n;
int m;

void comb(int cur, int len) {
  seq[len - 1] = input[cur];
  // visited[cur] = 1;
  if (len == m) {
    for (int i = 0; i < len; ++i) {
      printf("%d ", seq[i]);
    }
    printf("\n");
    // visited[cur] = 0;
    return;
  }

  for (int i = cur; i < n; ++i) {
    // if (visited[i]) {
    //   continue;
    // }
    comb(i, len + 1);
  }

  // visited[cur] = 0;
}

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

int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &input[i]);
  }
  sort(input, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    comb(i, 1);
  }
  return 0;
}