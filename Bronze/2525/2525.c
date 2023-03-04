#include <stdio.h>

int main(void)
{
	int	cur_hour;
	int	cur_min;
	int	end_hour;
	int	end_min;
	int	time_required;

	scanf("%d %d %d", &cur_hour, &cur_min, &time_required);
	end_hour = (cur_hour + (cur_min + time_required) / 60) % 24;
	end_min = (cur_min + time_required) % 60;
	printf("%d %d", end_hour, end_min);
	return (0);
}
