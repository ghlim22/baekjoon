#include <iostream>
#include <vector>

#define MAX (100)

std::vector<int> mat1[MAX];
std::vector<int> mat2[MAX];

int main(void)
{
	int	N;
	int	M;

	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int	input;
			std::cin >> input;
			mat1[i].push_back(input);
		}		
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int	input;
			std::cin >> input;
			mat2[i].push_back(input);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			mat1[i][j] += mat2[i][j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << mat1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
