#include <stdio.h>

static int power(int *arr, int base, int exp)
{
	int idx = 0;
	int tmp = 0;
	int carry = 0;

	arr[0] = 1;
	for (int i = 0; i < exp; ++i)
	{
		for (int j = 0; j <= idx; ++j)
		{
			tmp = carry + arr[j] * base;
			if (tmp >= 10) // generate carry-out.
			{
				carry = tmp / 10;
				arr[j] = tmp % 10;
				if (idx == j)
				{
					arr[++idx] = carry;
					carry = 0;
					break ;
				}
			}
			else
			{
				arr[j] = tmp;
				carry = 0;
			}	
		}
	}
	return (idx);
}

static void get_mersen_num(int *arr, int exp)
{
	int idx = power(arr, 2, exp);
	arr[0] -= 1;
	for (int i = idx; i >= 0; --i)
		printf("%d", arr[i]);
}

static void move(int dep, int arv)
{
	printf("%d %d\n", dep, arv);
}

void recursive(int n, int dep, int tmp, int arv)
{	
	if (n == 1)
	{
		move(dep, arv);
		return ;
	}

	recursive(n - 1, dep, arv, tmp);
	move(dep, arv);
	recursive(n - 1, tmp, dep, arv);
}

int main(void)
{
	int n;
	int arr[1000];

	scanf("%d", &n);
	get_mersen_num(arr, n);
	printf("\n");
	if (n <= 20)
		recursive(n, 1, 2, 3);
	return (0);
}