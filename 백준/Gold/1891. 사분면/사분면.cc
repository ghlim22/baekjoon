#include <iostream>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

long startY = 0;
long startX = 0;

void findYX(const std::string &num, int cur, int d) {
  if (cur == d) {
    return;
  }

  long halfLen = 1l << (d - cur - 1);
  switch (num[cur]) {
  case '1':
    startX += halfLen;
    break;
  case '3':
    startY += halfLen;
    break;
  case '4':
    startY += halfLen;
    startX += halfLen;
    break;
  }
  findYX(num, cur + 1, d);
}

void findNum(std::string &num, long y, long x, int d) {
  if (d == 0) {
    return;
  }

  char quadrant;
  long halfLen = (1l << (d - 1));
  if (y < halfLen) {
    if (x < halfLen) {
      quadrant = '2';
    } else {
      quadrant = '1';
      x -= halfLen;
    }
  } else {
    if (x < halfLen) {
      quadrant = '3';
    } else {
      quadrant = '4';
      x -= halfLen;
    }
    y -= halfLen;
  }

  num.push_back(quadrant);
  findNum(num, y, x, d - 1);
}

int main() {
  fastio;

  long d;
  long dx;
  long dy;
  std::string num;
  std::cin >> d >> num >> dx >> dy;

  findYX(num, 0, d);

  long length = (1l << d);
  long endY = startY - dy;
  long endX = startX + dx;

  if (!(endY >= 0 && endY < length && endX >= 0 && endX < length)) {
    std::cout << -1;
  } else {
    std::string endNum;
    findNum(endNum, endY, endX, d);
    std::cout << endNum;
  }

  return 0;
}