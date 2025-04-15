#include <stdio.h>
#include <string.h>

long ARRAY[100000];
long TEMP[100000];

void swap(long *a, long *b) {
  long tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(long *base, long size) {
  if (size <= 1) {
    return;
  }
  if (size <= 2) {
    if (base[0] > base[1]) {
      swap(&base[0], &base[1]);
    }
    return;
  }

  long *left = base;
  long *right = base + size / 2;
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

  memmove(base, TEMP, sizeof(long) * k);
}

int upperbound(long *base, int first, int last, long value) {
  while (first < last) {
    int mid = (first + last) / 2;
    if (base[mid] > value) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }
  return last;
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%ld", &ARRAY[i]);
  }
  sort(ARRAY, n);
  long max_num = 0;
  int max_count = 0;
  for (int i = 0; i < n;) {
    int upper = upperbound(ARRAY, i, n, ARRAY[i]);
    int count = upper - i;
    if (max_count < count) {
      max_count = count;
      max_num = ARRAY[i];
    }
    i = upper;
  }
  printf("%ld\n", max_num);
  return 0;
}