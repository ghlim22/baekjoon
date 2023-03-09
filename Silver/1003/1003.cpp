// https://www.acmicpc.net/problem/1003
// 1003번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

static long long arr_call0[41];
static long long arr_call1[41];

static void calculate(void)
{
	arr_call0[0] = 1;
	arr_call1[1] = 1;
	for (int i = 2; i <= 40; ++i)
	{
		arr_call0[i] = arr_call0[i - 1] + arr_call0[i - 2];
		arr_call1[i] = arr_call1[i - 1] + arr_call1[i - 2];
	}
	return ;
}

signed main() 
{
	fastio;
	int T, N;

	cin >> T;
	calculate();
	while (T--)
	{
		cin >> N;
		cout << arr_call0[N] << ' ' << arr_call1[N] << '\n';
	}
	return (0);
}