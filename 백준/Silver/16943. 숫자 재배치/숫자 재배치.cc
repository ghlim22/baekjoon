#include <iostream>

int A;
int B;
int LEN = 0;
int ARR[10];
int V[10];
int ANSWER = -1;

void solve(int num, int depth) {
	if (num >= B) {
		return;
	}
	if (depth == LEN) {
		ANSWER = num > ANSWER ? num : ANSWER;
		return;
	}

	int prev = num;
	for (int i = 0; i < LEN; ++i) {
		if (depth == 0 && ARR[i] == 0)
			continue;
		if (V[i])
			continue;
		V[i] = true;
		num = prev;
		num *= 10;
		num += ARR[i];
		solve(num, depth + 1);
		V[i] = false;
	}
}

int main(void) 
{
	std::cin >> A >> B;

	do {
		ARR[LEN++] = A % 10;
		A /= 10;
	} while (A > 0);

	solve(0, 0);

	std::cout << ANSWER;

	return 0;
}
