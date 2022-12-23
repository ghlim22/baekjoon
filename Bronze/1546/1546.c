#include <stdio.h>

int main(void)
{
	int subject_cnt, top_score;
	double res;

	res = 0.0;
	top_score = 0;
	scanf("%d", &subject_cnt);
	int scores[subject_cnt];
	for (int i = 0; i < subject_cnt; ++i)
	{
		scanf("%d", &scores[i]);
		if (scores[i] > top_score)
			top_score = scores[i];
	}
	for (int i = 0; i < subject_cnt; ++i)
		res += scores[i];
	res = res / top_score * 100.0 / subject_cnt;
	printf("%.12lf", res);

	return 0;
}