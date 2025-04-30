#include <iostream>
#include <stack>
#include <utility>

#define fastio                            \
	do                                    \
	{                                     \
		std::ios::sync_with_stdio(false); \
		std::cin.tie(0);                  \
		std::cout.tie(0);                 \
	} while (0)

struct card
{
	int left;
	int index;
	int right;
	int value;
};

typedef std::pair<int, int> pii_t;

long calc(const card &c)
{
	long left = c.index - c.left;
	left = left * (left + 1) / 2;

	long right = c.right - c.index;
	right = right * (right + 1) / 2;

	long n = c.right - c.left + 1;
	n = n * (n + 1) / 2 - left - right;

	return n * c.value;
}

int main(void)
{
	fastio;

	int N;
	long sum = 0;
	std::stack<card> maxStack, minStack;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		card c = {.left = i, .index = i, .right = i, .value = 0};
		std::cin >> c.value;

		while (!maxStack.empty() && maxStack.top().value <= c.value)
		{
			maxStack.top().right = c.index - 1;
			sum += calc(maxStack.top());
			c.left = maxStack.top().left;
			maxStack.pop();
		}
		maxStack.push(c);

		c.left = i;
		while (!minStack.empty() && minStack.top().value >= c.value)
		{
			minStack.top().right = c.index - 1;
			sum -= calc(minStack.top());
			c.left = minStack.top().left;
			minStack.pop();
		}
		minStack.push(c);
	}

	while (!maxStack.empty())
	{
		maxStack.top().right = N - 1;
		sum += calc(maxStack.top());
		maxStack.pop();
	}

	while (!minStack.empty())
	{
		minStack.top().right = N - 1;
		sum -= calc(minStack.top());
		minStack.pop();
	}

	std::cout << sum << '\n';

	return 0;
}