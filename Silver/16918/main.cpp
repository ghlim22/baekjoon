#include <stdio.h>

static int r, c, n, time;
static int board[200][200];
static int dx[4] = {-1, 1, 0, 0};
static int dy[4] = {0, 0, -1, 1};
int main(void)
{
	scanf("%d %d %d", &r, &c, &n);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			char c;
			scanf(" %c", &c);
			if (c == 'O')
				board[i][j] = 0;
			else
				board[i][j] = -1;
		}
	}
	time = 2;
	while (time <= n)
	{
		if (time % 2 == 0)
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if (board[i][j] == -1)
						board[i][j] = time;
				}
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (board[i][j] != -1 && board[i][j] == time - 3)
				{
					board[i][j] = -1;
					for (int k = 0; k < 4; ++k)
					{
						if (0 <= i + dy[k] && i + dy[k] < r && 0 <= j + dx[k] && j + dx[k] < c)
						{
							if (board[i + dy[k]][j + dx[k]] != time - 3)
								board[i + dy[k]][j + dx[k]] = -1;
						}
					}
				}
			}
		}
		time++;
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (board[i][j] == -1)
				printf(".");
			else
				printf("O");
		}
		printf("\n");
	}
	return 0;
}