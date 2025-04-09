#include <stdio.h>

int H[5] = {0, 2, 1, 4, 3};
int V[5] = {0, 4, 3, 2, 1};

int moveH(int *num, int cursor, int goRight) {
  if (cursor == -1)
    return 0;

  int recur = 0;
  int lastDigit = num[cursor];
  if (goRight) {
    if (lastDigit == 1 || lastDigit == 4) {
      recur = 1;
    }
  } else if (lastDigit == 2 || lastDigit == 3) {
    recur = 1;
  }

  if (recur && !moveH(num, cursor - 1, goRight)) {
    return 0;
  }

  num[cursor] = H[lastDigit];
  return 1;
}

int moveV(int *num, int cursor, int goUp) {
  if (cursor == -1)
    return 0;

  int recur = 0;
  int lastDigit = num[cursor];
  if (goUp) {
    if (lastDigit == 1 || lastDigit == 2) {
      recur = 1;
    }
  } else if (lastDigit == 3 || lastDigit == 4) {
    recur = 1;
  }

  if (recur && !moveV(num, cursor - 1, goUp)) {
    return 0;
  }

  num[cursor] = V[lastDigit];
  return 1;
}

int main(void) {
  int num[50];
  int len;
  long x;
  long y;

  scanf("%d", &len);
  for (int i = 0; i < len; ++i) {
    scanf("%1d", &num[i]);
  }
  scanf("%ld %ld", &x, &y);

  int fail = 0;

  int goRight = 1;
  if (x < 0) {
    goRight = 0;
    x = -x;
  }

  int goUp = 1;
  if (y < 0) {
    goUp = 0;
    y = -y;
  }

  for (int i = 0; i < len && x > 0 && !fail; ++i) {
    /* 2 ^ (len - 1 - i) is the length of a unit at level i */
    long count = x >> (len - 1 - i); /* x / (2 ^ (len - 1 - i)) */
    for (int j = 0; j < count; ++j) {
      if (!moveH(num, i, goRight)) {
        fail = 1;
        break;
      }
    }
    x &= ~(-1l << (len - 1 - i));
  }

  for (int i = 0; i < len && y > 0 && !fail; ++i) {
    long count = y >> (len - 1 - i);
    for (int j = 0; j < count; ++j) {
      if (!moveV(num, i, goUp)) {
        fail = 1;
        break;
      }
    }
    y &= ~(-1l << (len - 1 - i));
  }

  if (fail) {
    printf("-1\n");
  } else {
    for (int i = 0; i < len; ++i)
      printf("%d", num[i]);
    printf("\n");
  }

  return 0;
}