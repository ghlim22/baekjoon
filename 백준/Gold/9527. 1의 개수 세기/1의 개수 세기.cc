#include <iostream>

long cache[64]; // 2^(i+1)-1까지의 1의 개수의 누적합

long f(long n)
{
  if (n == 0 || n == 1)
    return n;
  int msb = 63;
  while (!(n >> msb))
    msb--;
  return cache[msb-1]+(n-(1L<<msb)+1)+f(n-(1L<<msb));
}

int main() 
{
  long a, b;
  std::cin >> a >> b;

  cache[0] = 1;
  for (int i = 1; i < 64; ++i) {
    cache[i] = cache[i-1] * 2 + (1L << i);
  }
  std::cout << f(b)-f(a-1);	
  return 0;
}
