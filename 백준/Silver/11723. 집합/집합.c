#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  uint32_t S = 0;
  int X;
  int M;
  char CMD[20];

  scanf("%d", &M);
  while (M--) {
    scanf("%s", CMD);

    if (strcmp(CMD, "all") == 0) {
      S = ~(0x0000);
    } else if (strcmp(CMD, "empty") == 0) {
      S = 0x0000;
    } else {
      scanf("%d", &X);
      if (strcmp(CMD, "add") == 0) {
        S |= (0x0001 << X);
      } else if (strcmp(CMD, "remove") == 0) {
        S &= ~(0x0001 << X);
      } else if (strcmp(CMD, "check") == 0) {
        printf("%d\n", (S & (0x0001 << X) ? 1 : 0));
      } else if (strcmp(CMD, "toggle") == 0) {
        S ^= (0x0001 << X);
      }
    }
  }
  return 0;
}