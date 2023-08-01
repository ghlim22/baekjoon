#include <iostream>

int main(void)
{
	int H;
	int M;

	std::cin >> H >> M;
	M -= 45;
	if (M < 0)
	{
		M += 60;
		H--;
		if (H < 0)
		 H += 24;
	}
	std::cout << H << ' ' << M << std::endl;
	return (0);
}
