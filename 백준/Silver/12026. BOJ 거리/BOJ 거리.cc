#include <cstring>
#include <iostream>

int D[1000];

int main()
{
	int N;
	std::string S;
	std::cin >> N >> S;
	std::memset(D, -1, sizeof(D));
	D[0] = 0;
	for (int i = 0; i < N; ++i) {
		if (D[i] == -1) {
			continue;
		}

		char next;
		if (S[i] == 'B')
			next = 'O';
		else if (S[i] == 'O')
			next = 'J';
		else
			next = 'B';

		for (int j = i + 1; j < N; ++j) {
			if (S[j] != next) {
				continue;
			}
			int k = j - i;
			int energy = k * k + D[i];
			if (D[j] == -1 || D[j] > energy) {
				D[j] = energy;
			}
		}
	}
	std::cout << D[N - 1];
	return 0;
}