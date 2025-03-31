#include <stdio.h>

int positive_nums[50];
int non_positive_nums[50];

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void mysort(int array[], int low, int high) {
  if (low >= high)
    return;

  int i = low;
  int j = low;
  int *pivot = &array[high];
  for (; i < high; ++i) {
    if (array[i] < *pivot)
      swap(&array[i], &array[j++]);
  }

  swap(&array[j], pivot);

  mysort(array, low, j - 1);
  mysort(array, j + 1, high);
}

int main(void) {
  int positive_nums_size = 0;
  int non_positive_nums_size = 0;
  int zero_cnt = 0;
  int n;

  scanf("%d", &n);
  while (n--) {
    int number;
    scanf("%d", &number);
    if (0 == number)
      zero_cnt++;
    if (number > 0)
      positive_nums[positive_nums_size++] = number;
    else
      non_positive_nums[non_positive_nums_size++] = number;
  }

  mysort(positive_nums, 0, positive_nums_size - 1);
  mysort(non_positive_nums, 0, non_positive_nums_size - 1);

  int sum = 0;
  // non-positive numbers
  // 절댓값이 큰 것부터 인접한 쌍끼리 묶는다.
  // 음수가 홀수 개 주어지면, 한 개의 음수가 남는다.
  // 0이 존재하면 남은 음수를 0과 묶고, 0이 없으면 수열의 합에 더한다.
  // 수열의 합에 더한다.
  int lmt = non_positive_nums_size - zero_cnt;
  for (int i = 0; i < lmt; ++i) {
    if (i + 1 < lmt) {
      sum += non_positive_nums[i] * non_positive_nums[i + 1];
      ++i;
    }
  }
  /* lmt >= 0 */
  if (zero_cnt == 0 && lmt % 2 != 0) {
    sum += non_positive_nums[lmt - 1];
  }

  // positive numbers
  // 큰 수부터 인접한 쌍끼리 묶는다.
  // 두 수의 곱보다 두 수의 합이 더 큰 경우를 고려한다. (두 수 중 1이 포함된
  // 경우)
  for (int i = positive_nums_size - 1; i >= 0; --i) {
    if (i - 1 >= 0 && positive_nums[i - 1] != 1) {
      sum += positive_nums[i] * positive_nums[i - 1];
      --i;
    } else {
      sum += positive_nums[i];
    }
  }

  printf("%d\n", sum);

  return 0;
}