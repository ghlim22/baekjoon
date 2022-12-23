#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int nums[8];
	bool is_ascending;
	bool is_descending;

	is_ascending = true;
	is_descending = true;

	for (int i = 0; i < 8; ++i)
	{
		scanf("%d", &nums[i]);
	}
	for (int i = 0; i < 7; ++i)
	{
		if (nums[i] > nums[i + 1])
		{
			is_ascending = false;
			break;
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		if (nums[i] < nums[i + 1])
		{
			is_descending = false;
			break;
		}
	}
	if (is_ascending)
		printf("ascending");
	else if (is_descending)
		printf("descending");
	else
		printf("mixed");

	return 0;
}