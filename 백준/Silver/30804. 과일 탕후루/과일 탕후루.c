#include <stdio.h>

int stick[200000];
int fruits[10];

int check() {
	int cnt = 0;
	for (int i = 1; i <= 9; ++i) {
		if (fruits[i] > 0)
			cnt++;
	}
	return cnt <= 2;
}

int main(void) {
	int N;

	scanf("%d", &N);
    for (int i = 0; i < N; ++i)
		scanf("%d", &stick[i]);

	int left = 0;
	int right = 0;
	int answer = 0;
	while (left < N) {
		while (right < N) {
			fruits[stick[right]]++;
			if (check()) {
				right++;
				int count = right - left;
				answer = (count > answer) ? count : answer;
			} else {
			    fruits[stick[right]]--;
				break;
			}
		}
		fruits[stick[left]]--;
		left++;
	}

	printf("%d\n", answer);

	return 0;
}