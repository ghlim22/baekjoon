#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	std::priority_queue<int> left;
	std::priority_queue<int, std::vector<int>, std::greater<int>> right;
	std::cin >> N;
	while (N--)
	{
		int num;
		std::cin >> num;

		if (left.empty())
		{
			left.push(num);
		}
		else
		{
			if (num > left.top())
			{
				right.push(num);
			}
			else
			{
				left.push(num);
			}
		}

		if (left.size() < right.size())
		{
			left.push(right.top());
			right.pop();
		}

		if (left.size() > right.size() + 1)
		{
			right.push(left.top());
			left.pop();
		}

		std::cout << left.top() << '\n';
	}

	return 0;
}