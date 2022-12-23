#include <stdio.h>
#include <string.h>

int main(void)
{
	int case_num;
	int len;
	int res;
	int ans_cnt;
	char str[81];

	scanf("%d", &case_num);
	for (int i = 0; i < case_num; ++i)
	{
		res = 0;
		ans_cnt = 0;
		scanf("%s", str);
		len = strlen(str);
		for (int j = 0; j < len; ++j)
		{
			if (str[j] == 'O')
			{
				ans_cnt++;
				res += ans_cnt;
			}
			else if (str[j] == 'X')
			{
				ans_cnt = 0;
			}
		}
		printf("%d\n", res);
	}
}