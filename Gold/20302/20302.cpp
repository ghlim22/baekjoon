// https://www.acmicpc.net/problem/20302
// 20302번 

#include <iostream>
#include <math.h>
#include <cassert>
#include <stdlib.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INTEGER_PROMPT ("mint chocolate")
#define RATIONAL_PROMPT ("toothpaste")
#define MAX (100000)

using namespace std;

static int prime_cnt[MAX + 1] = {0, };

static void factorize_add(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		while (n % i == 0)
		{
			n /= i;
			prime_cnt[i]++;
		}
	}
	if (n > 1)
		prime_cnt[n]++;
}

static void factorize_sub(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		while (n % i == 0)
		{
			n /= i;
			prime_cnt[i]--;
		}
	}
	if (n > 1)
		prime_cnt[n]--;
}

signed main() {
	fastio;

	int input;
	int num_cnt = 0;
	bool is_int = true;

	cin >> num_cnt;
	cin >> input;
	if (input == 0)
		goto PRINT;
	factorize_add(abs(input));
	for (int i = 1; i < num_cnt; ++i)
	{
		char op;

		cin >> op >> input;
		if (input == 0)
			goto PRINT;
		switch (op)
		{
		case '*':
			factorize_add(abs(input));
			break;
		case '/':
			factorize_sub(abs(input));
			break;
		default:
			break;
		}
	}

	for (int i = 2; i <= MAX; ++i)
	{
		if (prime_cnt[i] < 0)
		{
			is_int = false;
			break;
		}
	}

	PRINT:
	if (is_int)
		cout << INTEGER_PROMPT;
	else
		cout << RATIONAL_PROMPT;

	return (0);
}