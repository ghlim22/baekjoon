#include <algorithm>
#include <climits>
#include <iostream>

static int arr[1001];
static int t;
static int n;
static int tmp;
static int ans;

static int  find(int lo, int hi);

int main(void)
{
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
            std::cin >> arr[i + 1];       
		std::cout << find(1, n) << std::endl;
    }
    return 0;
}

static int max(int a, int b, int c)
{
    int max = std::max(a , b);
    return std::max(max, c);
}

static int  find(int lo, int hi)
{
	if (lo == hi)
		return arr[lo];
    int mid = (lo + hi) / 2;
	int	left = find(lo, mid);
	int	right = find(mid + 1, hi);
	int tmp = 0;
	int left_part = INT_MIN;
	for (int i = mid; i >= lo; --i)
	{
		tmp += arr[i];
		left_part = std::max(left_part, tmp);
	}
	int	right_part = INT_MIN;
	tmp = 0;
	for (int i = mid + 1; i <= hi; ++i)
	{
		tmp += arr[i];
		right_part = std::max(right_part, tmp);
	}
	return max(left, right, left_part + right_part);
}
