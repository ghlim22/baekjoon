#include <stdio.h>
#include <memory.h>
#include <string.h>

int main(void)
{
	int test_cnt;

	scanf("%d", &test_cnt);
	while (test_cnt--)
	{
		char type_save[30][21];
		int type_arr[30] = {0, };
		int type_cnt = 0;
		char name[21];
		char type[21];
		int ans = 1;
		int n;

		scanf("%d", &n);
		while (n--)
		{
			scanf("%s %s", name, type);
			int is_saved = 0;
			for (int i = 0; i < type_cnt; ++i)
			{
				if (!strcmp(type, type_save[i]))
				{
					is_saved = 1;
					type_arr[i]++;
					break;
				}
			}
			if (!is_saved)
			{
				type_arr[type_cnt]++;
				strcpy(type_save[type_cnt++], type);
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			ans *= type_arr[i] + 1;
		}
		printf("%d\n", ans - 1);
	}
	return (0);
}
