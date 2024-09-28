#include <stdio.h>

#define MAX (15)

int L;
int C;

char input[MAX];
char comb[MAX];

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(char *a, int low, int high) {
  if (low >= high) {
    return;
  }

  int i = low;
  int j = low;
  char *pivot = &a[high];
  for (; j < high; ++j) {
    if (a[j] < *pivot) {
      swap(&a[i++], &a[j]);
    }
  }
  swap(&a[i], pivot);

  sort(a, low, i - 1);
  sort(a, i + 1, high);
}

int is_vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void solve(int start, int len, int vowel, int consonant) {
  if (len == L) {
    if (vowel < 1 || consonant < 2) {
      return;
    }
    for (int i = 0; i < len; ++i) {
      printf("%c", comb[i]);
    }
    printf("\n");
    return;
  }
  for (int i = start; i < C; ++i) {
    comb[len] = input[i];
    if (is_vowel(comb[len])) {
      solve(i + 1, len + 1, vowel + 1, consonant);
    } else {
      solve(i + 1, len + 1, vowel, consonant + 1);
    }
  }
}

int main(void) {
  scanf("%d %d", &L, &C);
  for (int i = 0; i < C; ++i) {
    scanf(" %c", &input[i]);
  }
  sort(input, 0, C - 1);
  solve(0, 0, 0, 0);
  return 0;
}