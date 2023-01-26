#include <stdio.h>
#define INT_PROMPT ("mint chocolate")
#define RATIO_PROMPT ("toothpaste")

long long get_gcd(long long a, long long b)
{
	if (b == 0)
		return (a);
	return (b, a % b);
}

int main(void)
{
	int			num_cnt = 0;
	int			input;
	long long	numerator = 1;
	long long	denominator = 1;

	scanf("%d", &num_cnt);
	scanf("%d", &input);
	numerator *= input;
	for (int i = 1; i < num_cnt; ++i)
	{
		char operator;

		scanf(" %c %d", &operator, &input);
		switch (operator)
		{
		case '*':
			numerator *= input;
			break;
		case '/':
			denominator *= input;
			break;
		default:
			break;
		}
		long long gcd = get_gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	if (numerator % denominator == 0)
		printf("%s", INT_PROMPT);
	else
		printf("%s", RATIO_PROMPT);

	return (0);
}