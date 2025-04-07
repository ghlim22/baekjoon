#include <stdio.h>

int inorder[100000];
int postorder[100000];
int pos[100001];
int n;

void f(int ilo, int plo, int size) {
  if (size == 0) {
    return;
  }
  if (size == 1) {
    printf("%d ", postorder[plo]);
    return;
  }

  int root = postorder[plo + size - 1];
  int leftsize = pos[root] - ilo;

  printf("%d ", root);
  f(ilo, plo, leftsize);
  f(pos[root] + 1, plo + leftsize, size - leftsize - 1);
}

int main(void) {

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &inorder[i]);
    pos[inorder[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &postorder[i]);
  }
  f(0, 0, n);
  printf("\n");

  return 0;
}