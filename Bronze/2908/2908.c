#include <stdio.h>

static void print_rev(char num[4])
{
	for (int i = 2; i >= 0; --i)
		printf("%c", num[i]);
}

int main(void)
{
	char num1[4], num2[4];

	scanf("%s %s", num1, num2);
	if (num1[2] > num2[2])
		print_rev(num1);
	else if (num1[2] == num2[2] && num1[1] > num2[1])
		print_rev(num1);
	else if (num1[2] == num2[2] && num1[1] == num2[1] && num1[0] > num2[0])
		print_rev(num1);
	else
		print_rev(num2);
	return (0);
}