#include <stdio.h>
#include <stdlib.h>
#define MAX (1000)
static char	arr1[1000];
static char arr2[1000];

static char *add(char *a, char *b)
{	
	int	start_a = 0;
	int start_b = 0;
	int carry;
	int i;

	char *res = (char *)calloc(MAX, sizeof(char));
	while (start_a > MAX - 1 && a[start_a] == 0)
		start_a++;
	while (start_b > MAX - 1 && b[start_b] == 0)
		start_b++;
	int max_start = start_a <= start_b ? start_a : start_b;
	i = MAX - 1;
	carry = 0;
	while (i >= max_start)
	{
		int sum = a[i] + b[i];
		if (sum >= 10)
		{
			res[i] = carry + (sum % 10);
			carry = 1;
		}
		else
		{
			res[i] = carry + sum;
			carry = 0;
		}
		i--;
	}
	if (carry)
		res[i] = carry;
	return (res);
}

static void print_arr(char *arr)
{
	int start_idx = 0;

	while (start_idx < MAX - 1 && arr[start_idx] == 0)	
		start_idx++;
	for (int i = start_idx; i < MAX; ++i)
		printf("%d", arr[i]);
}

static int	is_zero(char *arr)
{
	int idx = 0;
	while (idx < MAX && arr[idx] == 0)
		idx++;
	return (idx == MAX);
}

static int is_same_num(char *a, char *b)
{
	int a_idx = 0;
	int b_idx = 0;

	while (a_idx < MAX - 1 && a[a_idx] == 0)
		a_idx++;
	while (b_idx < MAX - 1 && b[b_idx] == 0)
		b_idx++;
	if (a_idx != b_idx)
		return (0);
	for (int i = a_idx; i < MAX; ++i)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}

static char *number_one(void)
{
	char *res = (char *)calloc(MAX, sizeof(char));
	res[MAX - 1] = 1;
	return (res);
}

static char *minus_one(char *a)
{
	int start_idx = 0;
	int carry = 0;

	if (a[MAX - 1] > 0)
	{
		a[MAX - 1]--;
		return (a);
	}
	while (start_idx < MAX - 1 && a[start_idx])
		start_idx++;
	for (int i = MAX - 1; i >= start_idx; --i)
	{
		if (a[i] - 1 < 0)
		{
			a[i] = 0;
			carry = -1;
		}
		else
		{
			a[i] = a[i] - 1 + carry;
			carry = 0;
		}
	}
	return (a);
}

static char *comb(char *a, char *b)
{
	if (is_same_num(a, b) || is_zero(b))
		return (number_one());
	return (add(comb(minus_one(a), minus_one(b)), comb(minus_one(a), b))); 
}

static void put_num(char *arr, int num)
{
	for (int i = MAX - 1; i > 0; --i)
	{
		arr[i] = num % 10;
		num /= 10;
		if (!num)
			break;
	}
}

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	put_num(arr1, n);
	put_num(arr2, m);
	char *res = comb(arr1, arr2);
	print_arr(res);
	return (0);
}