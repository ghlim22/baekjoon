#include <stdio.h>

int H[5] = {0, 2, 1, 4, 3};
int V[5] = {0, 4, 3, 2, 1};

// long rightLeft(int len, long num, int isRight) {
//   if (len == 0)
//     return -1;

//   long prevNum = num / 10;
//   int lastDigit = num % 10;

//   if (isRight) {
//     if (lastDigit == 1 || lastDigit == 4) {
//       prevNum = rightLeft(len - 1, prevNum, isRight);
//     }
//   } else if (lastDigit == 2 || lastDigit == 3) {
//     prevNum = rightLeft(len - 1, prevNum, isRight);
//   }

//   if (prevNum == -1) {
//     return prevNum;
//   }
//   return prevNum * 10 + H[lastDigit];
// }

// long upDown(int len, long num, int isUp) {
//   if (len == 0)
//     return -1;

//   long prevNum = num / 10;
//   int lastDigit = num % 10;

//   if (isUp) {
//     if (lastDigit == 1 || lastDigit == 2) {
//       prevNum = upDown(len - 1, prevNum, isUp);
//     }
//   } else if (lastDigit == 3 || lastDigit == 4) {
//     prevNum = upDown(len - 1, prevNum, isUp);
//   }

//   if (prevNum == -1) {
//     return prevNum;
//   }
//   return prevNum * 10 + V[lastDigit];
// }

int hori(int *num, int cursor, int isRight) {
  if (cursor == -1)
    return 0;

  int recur = 0;
  int lastDigit = num[cursor];
  if (isRight) {
    if (lastDigit == 1 || lastDigit == 4) {
      recur = 1;
    }
  } else if (lastDigit == 2 || lastDigit == 3) {
    recur = 1;
  }

  if (recur && !hori(num, cursor - 1, isRight)) {
    return 0;
  }

  num[cursor] = H[lastDigit];
  return 1;
}

int vert(int *num, int cursor, int isUp) {
  if (cursor == -1)
    return 0;

  int recur = 0;
  int lastDigit = num[cursor];
  if (isUp) {
    if (lastDigit == 1 || lastDigit == 2) {
      recur = 1;
    }
  } else if (lastDigit == 3 || lastDigit == 4) {
    recur = 1;
  }

  if (recur && !vert(num, cursor - 1, isUp)) {
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

  if (x > 0) {
    for (int i = 0; i < len && x > 0 && !fail; ++i) {
      /* 2 ^ (len - 1 - i) is the length of a unit at level i */
      long count = x >> (len - 1 - i); /* x / (2 ^ (len - 1 - i)) */
      for (int j = 0; j < count; ++j) {
        if (!hori(num, i, 1)) {
          fail = 1;
          break;
        }
      }
      x &= ~(-1l << (len - 1 - i));
    }
  }

  if (x < 0) {
    x = -x;
    for (int i = 0; i < len && x > 0 && !fail; ++i) {
      long count = x >> (len - 1 - i);
      for (int j = 0; j < count; ++j) {
        if (!hori(num, i, 0)) {
          fail = 1;
          break;
        }
      }
      x &= ~(-1l << (len - 1 - i));
    }
  }

  if (y > 0) {
    for (int i = 0; i < len && y > 0 && !fail; ++i) {
      long count = y >> (len - 1 - i);
      for (int j = 0; j < count; ++j) {
        if (!vert(num, i, 1)) {
          fail = 1;
          break;
        }
      }
      y &= ~(-1l << (len - 1 - i));
    }
  }

  if (y < 0) {
    y = -y;
    for (int i = 0; i < len && y > 0 && !fail; ++i) {
      long count = y >> (len - 1 - i);
      for (int j = 0; j < count; ++j) {
        if (!vert(num, i, 0)) {
          fail = 1;
          break;
        }
      }
      y &= ~(-1l << (len - 1 - i));
    }
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