#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> neg;
	std::vector<int> pos;
	int zeros = 0;

	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		if (num < 0)
		{
			neg.push_back(num);
		}
		else if (num == 0)
		{
			zeros++;
		}
		else
		{
			pos.push_back(num);
		}
	}

	std::sort(neg.begin(), neg.end());
	std::sort(pos.begin(), pos.end());

	int sum = 0;
	for (int i = 0; i < (int)neg.size() - 1; i += 2)
	{
		sum += neg[i] * neg[i + 1];
	}

	if (zeros == 0 && neg.size() % 2 != 0)
	{
		sum += neg.back();
	}

	for (int i = (int)pos.size() - 1; i >= 0;)
	{
		if (i > 0 && pos[i - 1] != 1)
		{
			sum += pos[i] * pos[i - 1];
			i -= 2;
		}
		else
		{
			sum += pos[i];
			i--;
		}
	}

	std::cout << sum;

	return 0;
}
