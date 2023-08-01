#include <iostream>

#define LEN (9)

int main(void)
{
	int max = -1;
	int r;
	int c;
	for (int i = 0; i < LEN; ++i)
	{
		for (int j = 0; j < LEN; ++j)
		{
			int input;
			std::cin >> input;
			if (input > max)
			{
				r = i;
				c = j;
				max = input;
			}
		}
	}
	std::cout << max << std::endl;
	std::cout << (r + 1) << ' ' << (c + 1) << std::endl;
	return (0);
}