#include <iostream>
#define LEN (8)
int main(void)
{
	bool is_ascending = true;
	bool is_descending = true;
	int prev;
	int cur;
	for (int i = 0; i < LEN; ++i)
	{
		std::cin >> cur;
		if (i != 0)
		{
			if (prev < cur)
				is_descending = false;
			if (prev > cur)
				is_ascending = false;
		}
		prev = cur;
	}
	if (is_descending)
		std::cout << "descending\n";
	else if (is_ascending)
		std::cout << "ascending\n";
	else
		std::cout << "mixed\n";
	return (0);
}