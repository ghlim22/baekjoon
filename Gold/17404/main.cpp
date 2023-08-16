#include <algorithm>
#include <iostream>
#define SIZE (1000)
#define INF (3000)

typedef enum
{
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN
}	e_color;

static int	first_red[SIZE][3];
static int	first_blue[SIZE][3];
static int	first_green[SIZE][3];

int main(void)
{
	int	red;
	int	green;
	int	blue;
	int	cnt;
	int	i;

	std::cin >> cnt;
	std::cin >> red >> green >> blue;
	first_red[0][COLOR_RED] = red;
	first_red[0][COLOR_GREEN] = INF;
	first_red[0][COLOR_BLUE] = INF;
	first_blue[0][COLOR_RED] = INF;
	first_blue[0][COLOR_GREEN] = INF;
	first_blue[0][COLOR_BLUE] = blue;
	first_green[0][COLOR_RED] = INF;
	first_green[0][COLOR_GREEN] = green;
	first_green[0][COLOR_BLUE] = INF;
	for (i = 1; i < cnt; ++i)
	{
		std::cin >> red >> green >> blue;
		first_red[i][COLOR_RED] = red + std::min(first_red[i - 1][COLOR_BLUE], first_red[i - 1][COLOR_GREEN]);
		first_red[i][COLOR_GREEN] = green + std::min(first_red[i - 1][COLOR_RED], first_red[i - 1][COLOR_BLUE]);
		first_red[i][COLOR_BLUE] = blue + std::min(first_red[i - 1][COLOR_RED], first_red[i - 1][COLOR_GREEN]);
		first_green[i][COLOR_RED] = red + std::min(first_green[i - 1][COLOR_BLUE], first_green[i - 1][COLOR_GREEN]);
		first_green[i][COLOR_GREEN] = green + std::min(first_green[i - 1][COLOR_RED], first_green[i - 1][COLOR_BLUE]);
		first_green[i][COLOR_BLUE] = blue + std::min(first_green[i - 1][COLOR_RED], first_green[i - 1][COLOR_GREEN]);
		first_blue[i][COLOR_RED] = red + std::min(first_blue[i - 1][COLOR_BLUE], first_blue[i - 1][COLOR_GREEN]);
		first_blue[i][COLOR_GREEN] = green + std::min(first_blue[i - 1][COLOR_RED], first_blue[i - 1][COLOR_BLUE]);
		first_blue[i][COLOR_BLUE] = blue + std::min(first_blue[i - 1][COLOR_RED], first_blue[i - 1][COLOR_GREEN]);
	}

	i--;
	int ans = std::min(first_red[i][COLOR_GREEN], first_red[i][COLOR_BLUE]);
	ans = std::min(std::min(first_green[i][COLOR_RED], first_green[i][COLOR_BLUE]), ans);
	ans = std::min(std::min(first_blue[i][COLOR_RED], first_blue[i][COLOR_GREEN]), ans);
	std::cout << ans;

	return (0);
}