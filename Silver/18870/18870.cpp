// <https://www.acmicpc.net/problem/18870>
// 18870번 

#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

int b_search(int arr[], int start, int end, int key)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == key)
			return (mid);
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);
}

signed main() {
	fastio;

	int size = 0;
	int sorted_size = 0;
	cin >> size;
	int inputs[size];
	int cpy[size];
	int sorted_arr[size];
	for (int i = 0; i < size; ++i)
		cin >> inputs[i];

	memcpy(cpy, inputs, sizeof(int) * size);
	sort(cpy, cpy + size);

	sorted_arr[sorted_size++] = cpy[0];
	for (int i = 1; i < size; ++i)
	{
		if (cpy[i] != cpy[i - 1])
			sorted_arr[sorted_size++] = cpy[i];
	}

	for (int i = 0; i < size; ++i)
	{
		cout << b_search(sorted_arr, 0, sorted_size - 1, inputs[i]) << ' ';
	}

	return (0);
}		