#include <stdio.h>

int sorted_list[1000000];

int lowerbound(int array[], int size, int key) {
  int low = 0;
  int high = size;
  while (low < high) {
    int mid = (low + high) / 2;
    if (array[mid] >= key)
      high = mid;
    else
      low = mid + 1;
  }
  return high;
}

int main(void) {
  int n;
  int number;
  int length = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &number);
    int pos = lowerbound(sorted_list, length, number);
    if (pos == length) {
      length++;
    }
    sorted_list[pos] = number;
  }

  printf("%d\n", length);

  return 0;
}