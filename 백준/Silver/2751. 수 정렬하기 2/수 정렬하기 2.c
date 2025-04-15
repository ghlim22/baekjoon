#include <stdio.h>
#include <string.h>

int ARRAY[1000000];
int TEMP[1000000];

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *base, int size) {
  if (size <= 1) {
    return;
  }
  if (size <= 2) {
    if (base[0] > base[1]) {
      swap(&base[0], &base[1]);
    }
    return;
  }

  int *left = base;
  int *right = base + size / 2;
  const int LEFT_SIZE = size / 2;
  const int RIGHT_SIZE = (size + 1) / 2;

  sort(left, LEFT_SIZE);
  sort(right, RIGHT_SIZE);

  int i = 0;
  int j = 0;
  int k = 0;
  while (i < LEFT_SIZE && j < RIGHT_SIZE) {
    if (left[i] <= right[j]) {
      TEMP[k++] = left[i++];
    } else {
      TEMP[k++] = right[j++];
    }
  }

  while (i < LEFT_SIZE) {
    TEMP[k++] = left[i++];
  }
  while (j < RIGHT_SIZE) {
    TEMP[k++] = right[j++];
  }

  memmove(base, TEMP, sizeof(int) * k);
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ARRAY[i]);
  }
  sort(ARRAY, n);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ARRAY[i]);
  }
  return 0;
}