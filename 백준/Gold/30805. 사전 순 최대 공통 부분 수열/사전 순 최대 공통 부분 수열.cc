#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define SIZE 100

struct number {
	int value;
	int index;
	bool operator() (const number& a, const number &b) {
		if (a.value == b.value)
			return a.index < b.index;
		return a.value > b.value;
	}
};

number A[SIZE];
number B[SIZE];

int main()
{
	int N, M, num;
	std::priority_queue<number, std::vector<number>, number> aq, bq;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i].value;
		A[i].index = i;
	}

	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> B[i].value;
		B[i].index = i;
	}

	number cmp;
	std::sort(A, A + N, cmp);
	std::sort(B, B + M, cmp);

	int aindex=-1;
	int bindex=-1;
	std::vector<int> seq;
	for (int i=0,j=0; i < N && j < M;) {
		while (i < N && j < M && (A[i].value > B[j].value || A[i].index < aindex)) {
			++i;
		}
		while (i < N && j < M && (A[i].value < B[j].value || B[j].index < bindex)) {
			++j;
		}
		if (i < N && j < M && A[i].value == B[j].value) {
			seq.push_back(A[i].value);
			aindex = A[i].index;
			bindex = B[j].index;
			i++;
			j++;
		}
	}

	std::cout << seq.size() << '\n';
	for (int n : seq)
		std::cout << n << ' ';

	return 0;
}