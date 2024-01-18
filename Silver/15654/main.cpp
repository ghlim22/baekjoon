#include <iostream>

#define SWAP(x, y) \
	do {	\
		int tmp = (x); \
		(x) = y; \
		(y) = tmp; \
	} while (0) \

int n;
int m;
int arr[100];
int print[100];
int vis[100];

void ft_sort(int arr[], int start, int end);
void print_seq(int dep, int cur);

int main(void)
{

	std::cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	ft_sort(arr, 0, n - 1);
	print_seq(0, -1);
	return 0;
}

void ft_sort(int arr[], int start, int end)
{
	int left = start;
	int right = end;
	int pivot = arr[(start + end) / 2];

	do {
		while (left <= end && arr[left] < pivot) {
			++left;
		}
		while (right >= start && arr[right] > pivot) {
			--right;
		}
		if (left <= right) {
			SWAP(arr[left], arr[right]);
			++left;
			--right;
		}
	} while (left <= right);

	if (start < right) {
		ft_sort(arr, start, right);
	}
	if (left < end) {
		ft_sort(arr, left, end);
	}
}

void print_seq(int dep, int cur)
{
	if (dep == m) {
		for (int i = 0; i < m; ++i) {
			std::cout << print[i];
			if (i < m - 1) {
				std::cout << ' ';
			}
		}
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			print[dep] = arr[i];
			print_seq(dep + 1, i);
			vis[i] = 0;
		}
	}
}
