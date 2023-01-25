// <https://www.acmicpc.net/problem/2981>
// 2981번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int get_gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (get_gcd(b, a % b));
}

static int get_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

signed main() {
	fastio;
	int num_cnt = 0;
	int diff_cnt = 0;
	int gcd = 0;
	int input_arr[100] = {0, };
	int difference_arr[4950] = {0, };

	cin >> num_cnt;
	for (int i = 0; i < num_cnt; ++i)
		cin >> input_arr[i];
	for (int i = 0; i < num_cnt; ++i)
	{
		for (int j = i + 1; j < num_cnt; ++j)
		{
			difference_arr[diff_cnt++] = get_abs(input_arr[i] - input_arr[j]);
		}
	}

	gcd = difference_arr[0];
	for (int i = 1; i < diff_cnt; ++i)
	{
		gcd = get_gcd(difference_arr[i], gcd);
	}
	
	for (int i = 2; i < gcd; ++i)
	{
		if (gcd % i == 0)
			cout << i << ' ';
	}
	cout << gcd;

	return (0);
}