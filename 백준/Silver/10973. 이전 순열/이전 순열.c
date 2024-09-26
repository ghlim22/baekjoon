#include <stdio.h>

#define MAX (10000)

void input(int *arr, int *n) {
  scanf("%d", n);
  for (int i = 0; i < *n; ++i) {
    scanf("%d", &arr[i]);
  }
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* [start, end) */
void reverse(int *a, int start, int end) {
  const int REP = (end - start) / 2;
  for (int i = 0; i < REP; ++i) {
    swap(&a[start + i], &a[end - 1 - i]);
  }
}

/* [start, end) */
void print(const int *a, int start, int end) {
  for (int i = start; i < end; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void next_permutation(int *arr, const int n) {
  /* Identify the rightmost element that is greater than its next. This element
   * is called pivot. */
  int pivot = -1;
  for (int i = n - 2; i >= 0; --i) {
    if (arr[i] > arr[i + 1]) {
      pivot = i;
      break;
    }
  }

  /* If permutation is sorted in increasing order then it must be the first one.
   */
  if (pivot == -1) {
    printf("-1");
    return;
  }

  /* Find the rightmost element that is smaller than the pivot */
  for (int i = n - 1; i > pivot; --i) {
    if (arr[i] < arr[pivot]) {
      swap(&arr[i], &arr[pivot]);
      break;
    }
  }

  /* Reverse the elements to the right of the pivot. */
  reverse(arr, pivot + 1, n);
  print(arr, 0, n);
}

int main(void) {
  int n;
  int arr[MAX];

  input(arr, &n);
  next_permutation(arr, n);

  return 0;
}