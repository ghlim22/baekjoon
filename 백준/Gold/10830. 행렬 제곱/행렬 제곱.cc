#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix multiply(const matrix &a, const matrix &b)
{
	matrix c(a.size());

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a.size(); ++j)
		{
			c[i].push_back(0);
			for (int k = 0; k < a.size(); ++k)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}

	return c;
}

int main()
{
	int N;
	long B;

	std::cin >> N >> B;

	matrix A(N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int num;
			std::cin >> num;
			A[i].push_back(num);
		}
	}

	matrix res(N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				res[i].push_back(1);
			else
				res[i].push_back(0);
		}
	}

	while (B > 0)
	{
		if (B & 1L)
		{
			res = multiply(res, A);
		}
		A = multiply(A, A);
		B >>= 1;
	}

	for (auto &row : res)
	{
		for (int num : row)
		{
			std::cout << num << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}