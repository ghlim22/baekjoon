#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define BOARD_SIZE (9)

static int board[BOARD_SIZE][BOARD_SIZE];

static void get_input(void);
static void solve_recursive(int depth);

int main(void)
{
	get_input();
	solve_recursive(0);
	return (0);
}

static void get_input(void)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			scanf("%1d", &board[i][j]);
		}
	}
}

static void print_board(void)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			printf("%1d", board[i][j]);
		}
		printf("\n");
	}
}

static bool check_cross(int num, int row, int col)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board[row][i] == num)
			return (false);
		if (board[i][col] == num)
			return (false);
	}
	return (true);
}

static bool check_box(int num, int row, int col)
{
	int box_start = (row / 3) * 27 + (col / 3) * 3;
	row = box_start / 9;
	col = box_start % 9;
	for (int i = row; i < row + 3; ++i)
	{
		for (int j = col; j < col + 3; ++j)
		{
			if (board[i][j] == num)
				return (false);
		}
	}
	return (true);
}

static void solve_recursive(int depth)
{
	if (depth == 81)
	{
		print_board();
		exit(EXIT_SUCCESS);
	}
	int row = depth / 9;
	int col = depth % 9;
	if (!board[row][col])
	{
		for (int i = 1; i <= 9; ++i)
		{
			if (check_box(i, row, col) && check_cross(i, row, col))
			{
				board[row][col] = i;
				solve_recursive(depth + 1);
				board[row][col] = 0;
			}
		}
	}
	else
	{
		solve_recursive(depth + 1);
	}
}
