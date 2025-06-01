#include <iostream>

char answer[51];
int N;
int count[3];
bool D[50][50][50][3][3];

bool f(int index, int p1, int p2)
{
	if (index == N) {
		return true;
	}

	if (D[count[0]][count[1]][count[2]][p1-'A'][p2-'A'])
		return false;

	D[count[0]][count[1]][count[2]][p1-'A'][p2-'A'] = true;

	for (int i = 0; i < 3; ++i) {
		if (count[i] <= 0)
			continue;

		if (i == 1 && p1 == 'B') {
			continue;
		}

		if (i == 2 && (p1 == 'C' || p2 == 'C')) {
			continue;
		}
		
		count[i] -= 1;
		answer[index] = 'A' + i;
		if (f(index + 1, answer[index], p1))
			return true;
		count[i] += 1;
	}

	return false;
}

int main()
{
	std::string S;
	std::cin >> S;
	N = S.size();
	for (int i = 0; i < N; ++i) {
		count[S[i] - 'A'] += 1;
	}
	if (f(0, 'A', 'A')) {
		std::cout << answer;
	} else {
		std::cout << -1;
	}
	return 0;
}