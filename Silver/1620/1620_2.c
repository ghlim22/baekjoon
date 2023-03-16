#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX (100000)

typedef struct	s_info
{
	char	name[21];
	int		num;
}				t_info;

typedef struct s_node
{
	t_info			*monster_info;
	struct s_node	*next;
}				t_node;

typedef	struct s_table
{
	t_node	*node;
	int		cnt;
}				t_table;

t_info		info_arr[MAX];
t_table		table_arr[MAX];
static int	M;
static int	N;

static int	hash_func(char *str)
{
	int	res = 0;
	for (int i = 0; str[i]; ++i)
		res += (str[i] * (i + 1));
	return (res % MAX);
}

static void	init_table(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		table_arr[i].node = NULL;
		table_arr[i].cnt = 0;
	}
}

static void	get_input(void)
{
	t_node	*new_node;

	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; ++i)
	{
		scanf(" %s", info_arr[i].name);
		info_arr[i].num = i + 1;
		int hash = hash_func(info_arr[i].name);
		new_node = (t_node *)malloc(sizeof(t_node));
		new_node->next = 0;
		new_node->monster_info = &info_arr[i];
		if (table_arr[hash].node == NULL)
		{
			table_arr[hash].node = new_node;
			table_arr[hash].cnt = 1;
		}
		else
		{
			t_node	*cur = table_arr[hash].node;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = new_node;
			table_arr[hash].cnt++;
		}
		new_node = NULL;
	}
}

static void	find_monster(void)
{
	char tmp[21];

	for (int i = 0; i < N; ++i)
	{
		scanf(" %[^\n]", tmp);
		if (isdigit(tmp[0]))
		{
			printf("%s\n", info_arr[atoi(tmp) - 1].name);
		}
		else
		{
			int hash = hash_func(tmp);
			if (table_arr[hash].cnt == 1)
			{
				printf("%d\n", table_arr[hash].node->monster_info->num);
			}
			else
			{
				t_node	*cur = table_arr[hash].node;
				while (cur != NULL)
				{
					if (!strcmp(tmp, cur->monster_info->name))
					{
						printf("%d\n", cur->monster_info->num);
					}
					cur = cur->next;
				}
			}
		}
	}
}

int main(void)
{
	init_table();
	get_input();
	find_monster();
	return (0);
}
