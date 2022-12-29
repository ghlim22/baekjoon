#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _number
{
	int value;
	int appear;
	struct _number *next;
}number;


void add_number(number **head, int num);
number *new_nubmer(int num);
number *is_appeared(number *head, int num);

void add_number(number **head, int num)
{
	number *prev = NULL;
	number *cur = NULL;
	if (!*head)
	{
		*head = new_nubmer(num);
		return ;
	}
	if ((cur = is_appeared(*head, num)))
	{
		cur->appear++;
		return ;
	}
	number *new = new_nubmer(num);
	for (cur = *head; cur; )
	{
		prev = cur;
		cur = cur->next;
		if (num < cur->value)
		{
			break;
		}
	}
	if (prev == cur)
	{
		if (prev == *head)
			*head = new;
		
	}
	else
		prev->next = new;
	new->next = cur;
}

number *new_nubmer(int num)
{
	number *new = (number *)malloc(sizeof(number));
	new->value = num;
	new->appear = 1;
	new->next = NULL;
	return new;
}

number *is_appeared(number *head, int num)
{
	number *cur = NULL;

	for (cur = head; cur; cur = cur->next)
	{
		if (cur->value == num)
			return cur;
	}
	return NULL;
}

void free_lst(number **head)
{
	number *cur;
	number *next;

	for (cur = *head; cur; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	*head = NULL;
}
/*
number *search(number *head, int num)
{
	number *cur;

	for (cur = head; cur; cur = cur->next)
	{
		if (cur->value == num)
			return (cur);
	}
	return (NULL);
}
*/
/*
int compare(const void *first, const void *second)
{
	int *a = (int *)first;
	int *b = (int *)second;

	if (*a > *b)
		return 1;
	else if (*a == *b)
		return 0;
	return -1;
}



int get_mean(int *arr, int size)
{
}

int get_median(int *arr, int size)
{
}

int get_mode(int *arr, int size)
{
	
}

int get_range(int *arr, int size)
{

}
*/

int main(void)
{
	/*
	int N;
	int arithmetic_mean;
	int median;
	int mode;
	int range;
	int tmp;

	scanf("%d", N);
	for (int i = 0; i < N; ++i)
	{
		
	}
	*/

	int N;
	int tmp;
	number *head;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &tmp);
		add_number(&head, tmp);
	}

	number *cur;
	for (cur = head; cur; cur = cur->next)
	{
		printf("val: %d apperances: %d\n", cur->value, cur->appear);
	}

	free_lst(&head);

	return 0;
}