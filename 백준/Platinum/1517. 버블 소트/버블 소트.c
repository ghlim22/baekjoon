#include <stdio.h>
#include <string.h>

int g_array[500000];
int g_sorted[500000];
long g_swap_count = 0;

void merge_sort(int arr[], int lo, int hi) {
  if (lo >= hi)
    return;

  int mid = (lo + hi) / 2;
  merge_sort(arr, lo, mid);
  merge_sort(arr, mid + 1, hi);

  int left = lo;
  int right = mid + 1;
  int len = 0;
  long count = 0;
  while (left <= mid && right <= hi) {
    if (arr[left] <= arr[right]) {
      g_sorted[len++] = arr[left++];
    } else {
      count += (mid - left + 1);
      g_sorted[len++] = arr[right++];
    }
  }
  while (left <= mid)
    g_sorted[len++] = arr[left++];
  while (right <= hi)
    g_sorted[len++] = arr[right++];

  g_swap_count += count;
  memmove(arr + lo, g_sorted, sizeof(int) * len);
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &g_array[i]);

  merge_sort(g_array, 0, n - 1);

  printf("%ld\n", g_swap_count);

  return 0;
}
