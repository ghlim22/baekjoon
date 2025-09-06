#include <stdio.h>

int min(int x, int y) {
	return ((x < y) ? x : y);
}

int max(int x, int y) {
	return ((x > y) ? x : y);
}

int main(void) {
	int n;
	int nums[100000][3];
	int min_score[3];
	int max_score[3];
	int tmp[3];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j)
			scanf("%d", &nums[i][j]);
	}

	for (int i = 0; i < 3; ++i) {
		min_score[i] = nums[0][i];
		max_score[i] = nums[0][i];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (j == 0)
				tmp[j] = nums[i][j] + min(min_score[j], min_score[j + 1]);
			else if (j == 1)
				tmp[j] = nums[i][j] + min(min_score[j], min(min_score[j - 1], min_score[j + 1]));
			else
				tmp[j] = nums[i][j] + min(min_score[j], min_score[j - 1]);
		}
		for (int j = 0; j < 3; ++j)
			min_score[j] = tmp[j];

		
		for (int j = 0; j < 3; ++j) {
			if (j == 0)
				tmp[j] = nums[i][j] + max(max_score[j], max_score[j + 1]);
			else if (j == 1)
				tmp[j] = nums[i][j] + max(max_score[j], max(max_score[j - 1], max_score[j + 1]));
			else
				tmp[j] = nums[i][j] + max(max_score[j], max_score[j - 1]);
		}
		for (int j = 0; j < 3; ++j)
			max_score[j] = tmp[j];
	}

	int min_value = min(min_score[0], min(min_score[1], min_score[2]));
	int max_value = max(max_score[0], max(max_score[1], max_score[2]));

	printf("%d %d\n", max_value, min_value);
	
	
	return 0;
}