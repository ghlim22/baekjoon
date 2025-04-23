#include <cstdio>
#include <ctype.h>
#include <cstdlib>
#include <stack>

int main()
{
	char *line = NULL;
	size_t n;
	size_t len = getline(&line, &n, stdin);

	std::stack<int> s;
	char *startptr = line;
	while (*startptr != '\0')
	{
		char *endptr;
		int num = strtol(startptr, &endptr, 10);
		if (num < 0)
		{
			s.push(-num);
		}
		else
		{
			if (s.empty())
			{
				s.push(num);
			}
			else
			{
				s.top() += num;
			}
		}
		startptr = endptr;
		if (!isdigit(*startptr) && *startptr != '+' && *startptr != '-')
			break;
	}
	free(line);

	int minusSum = 0;
	while (s.size() > 1)
	{
		minusSum += s.top();
		s.pop();
	}
	s.top() -= minusSum;
	printf("%d", s.top());
	return 0;
}