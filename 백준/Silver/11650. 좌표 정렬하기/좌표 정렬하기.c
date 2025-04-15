#include <stdio.h>
#include <string.h>

typedef struct s_point {
  int x;
  int y;
} t_point;

t_point ARRAY[100000];
t_point TEMP[100000];

void swap(t_point *a, t_point *b) {
  t_point tmp = *a;
  *a = *b;
  *b = tmp;
}

int less(const t_point *a, const t_point *b) {
  if (a->x == b->x) {
    return a->y < b->y;
  }
  return a->x < b->x;
}

void sort(t_point *base, int size) {
  if (size <= 1) {
    return;
  }
  if (size <= 2) {
    if (less(&base[1], &base[0])) {
      swap(&base[1], &base[0]);
    }
    return;
  }

  t_point *left = base;
  t_point *right = base + size / 2;
  const int LEFT_SIZE = size / 2;
  const int RIGHT_SIZE = (size + 1) / 2;

  sort(left, LEFT_SIZE);
  sort(right, RIGHT_SIZE);

  int i = 0;
  int j = 0;
  int k = 0;
  while (i < LEFT_SIZE && j < RIGHT_SIZE) {
    if (less(&right[j], &left[i])) {
      TEMP[k++] = right[j++];
    } else {
      TEMP[k++] = left[i++];
    }
  }

  while (i < LEFT_SIZE) {
    TEMP[k++] = left[i++];
  }
  while (j < RIGHT_SIZE) {
    TEMP[k++] = right[j++];
  }

  memmove(base, TEMP, sizeof(t_point) * k);
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &ARRAY[i].x, &ARRAY[i].y);
  }
  sort(ARRAY, n);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", ARRAY[i].x, ARRAY[i].y);
  }
  return 0;
}