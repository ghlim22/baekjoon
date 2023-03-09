#include <stdio.h>
#include <string.h>

static int arr[21];

static void m_add(int x)
{
	if (arr[x])
		return ;
	arr[x] = 1;
}

static void m_remove(int x)
{
	if (!arr[x])
		return ;
	arr[x] = 0;
}

static void m_check(int x)
{
	printf("%d\n", arr[x]);
}

static void m_toggle(int x)
{
	if (arr[x])
		arr[x] = 0;
	else
		arr[x] = 1;
}

static void m_all(void)
{
	for (int i = 1; i <= 20; ++i)
		arr[i] = 1;
}

static void m_empty(void)
{
	for (int i = 1; i <= 20; ++i)
		arr[i] = 0;
}


int main(void)
{
	int M, x;
	char cmd[10] = {0, };

	scanf("%d", &M);
	while (M--)
	{
		scanf("%s", cmd);
		if (!strcmp("add", cmd))
		{
			scanf("%d", &x);
			m_add(x);
		}
		else if (!strcmp("remove", cmd))
		{
			scanf("%d", &x);
			m_remove(x);
		}
		else if (!strcmp("check", cmd))
		{
			scanf("%d", &x);
			m_check(x);
		}
		else if (!strcmp("toggle", cmd))
		{
			scanf("%d", &x);
			m_toggle(x);
		}
		else if (!strcmp("all", cmd))
		{
			m_all();
		}
		else if (!strcmp("empty", cmd))
		{
			m_empty();
		}
	}
	return (0);
}