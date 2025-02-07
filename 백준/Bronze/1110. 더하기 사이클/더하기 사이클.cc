#include <iostream>

int main(void) {
  int N;
  int num;
  int sum;
  int cycle;

  std::cin >> N;
  cycle = 0;
  num = N;
  do {
    sum = num / 10 + num % 10;
    num = (num % 10) * 10 + (sum % 10);
    cycle++;
  } while (num != N);
  std::cout << cycle << std::endl;

  return 0;
}