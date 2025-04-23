#include <iostream>

int main()
{
	std::string S, T;

	std::cin >> S >> std::ws >> T;

	while (T.size() > S.size())
	{
		if (T.back() == 'A')
		{
			T.pop_back();
		}
		else
		{
			T.pop_back();
			for (int i = 0; i < T.size() / 2; ++i)
				std::swap(T[i], T[T.size() - 1 - i]);
		}
	}

	std::cout << (T==S);

	return 0;
}