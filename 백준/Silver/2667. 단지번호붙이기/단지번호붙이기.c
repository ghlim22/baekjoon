#include <stdio.h>

#define MAX (25)

int n;
int map[MAX][MAX];
int counts[MAX * MAX / 2 + 1];
const int DX[4] = {-1, 0, 0, 1};
const int DY[4] = {0, -1, 1, 0};

int search(int y, int x) {
  map[y][x] = 0;
  int cnt = 1;
  for (int i = 0; i < 4; ++i) {
    int ny = y + DY[i];
    int nx = x + DX[i];
    if (!(ny >= 0 && ny < n))
      continue;
    if (!(nx >= 0 && nx < n))
      continue;
    if (map[ny][nx] == 0)
      continue;
    cnt += search(ny, nx);
  }

  return cnt;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *a, int low, int high) {
  if (low >= high)
    return;

  int i = low;
  int j = low;
  int *p = &a[high];
  for (; j < high; ++j) {
    if (a[j] < *p) {
      swap(&a[i++], &a[j]);
    }
  }
  swap(&a[i], p);

  sort(a, low, i - 1);
  sort(a, i + 1, high);
}

int main(void) {

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%1d", &map[i][j]);
    }
  }

  int size = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j]) {
        counts[size++] = search(i, j);
      }
    }
  }
  
  printf("%d\n", size);
  sort(counts, 0, size - 1);
  for (int i = 0; i < size; ++i) {
    printf("%d\n", counts[i]);
  }

  return 0;
}