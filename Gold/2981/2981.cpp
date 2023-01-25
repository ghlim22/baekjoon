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
	int gcd = 0;
	int arr[100] = {0, };

	cin >> num_cnt;
	for (int i = 0; i < num_cnt; ++i)
		cin >> arr[i];
	for (int i = 0; i < num_cnt; ++i)
	{
		for (int j = i + 1; j < num_cnt; ++j)
		{
			int difference = get_abs(arr[i] - arr[j]);
			gcd = get_gcd(difference, gcd);
		}
	}
	for (int i = 2; i <= gcd / 2; ++i)
	{
		if (gcd % i == 0)
			cout << i << ' ';
	}
	cout << gcd;

	return (0);
}