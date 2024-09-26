#include <stdio.h>
#include <string.h>

void print(int *a, int start, int end) {
  for (int i = start; i < end; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void permutation(int *a, int *v, int curr, int n) {
  if (curr == n) {
    print(a, 0, n);
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (v[i]) {
      continue;
    }
    v[i] = 1;
    a[curr] = i;
    permutation(a, v, curr + 1, n);
    v[i] = 0;
  }
}

int main(void) {
  int arr[8];
  int visited[9];
  int n;

  memset(visited, 0, sizeof(visited));

  scanf("%d", &n);

  permutation(arr, visited, 0, n);

  return 0;
}