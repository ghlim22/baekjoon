#include <stdio.h>

static int get_gcd(int a, int b)
{
	int remainder;

	while (b)
	{
		remainder = a % b;
		a = b;
		b = remainder;	
	}
	return a;
}

static int get_lcm(int a, int b)
{
	return (a * b) / get_gcd(a, b);
}

int main(void)
{
	int num1;
	int num2;

	scanf("%d %d", &num1, &num2);
	if (num1 < num2)
	{
		num1 ^= num2;
		num2 ^= num1;
		num1 ^= num2;
	}
	printf("%d\n%d\n", get_gcd(num1, num2), get_lcm(num1, num2));
	return 0;
}