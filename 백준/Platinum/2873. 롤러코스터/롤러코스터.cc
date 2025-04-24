#include <iostream>
#include <algorithm>

int map[1000][1000];

struct coord
{
	int y;
	int x;
};

void append(std::string &s, char c, int n)
{
	for (int i = 0; i < n; ++i)
		s.push_back(c);
}

coord findNotVisit(int r, int c)
{
	coord notVisit = {.y = 0, .x = 1};
	for (int y = 0; y < r; ++y)
	{
		for (int x = 0; x < c; ++x)
		{
			if ((y + x) % 2 == 0)
				continue;
			if (map[y][x] < map[notVisit.y][notVisit.x])
			{
				notVisit.y = y;
				notVisit.x = x;
			}
		}
	}

	return notVisit;
}

int main()
{
	int r;
	int c;

	std::cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			std::cin >> map[i][j];
	}

	std::string s;

	if (r % 2 != 0)
	{
		for (int i = 0; i < r; ++i)
		{
			if (i % 2 == 0)
			{
				append(s, 'R', c - 1);
			}
			else
			{
				append(s, 'L', c - 1);
			}

			if (i < r - 1)
			{
				append(s, 'D', 1);
			}
		}
	}
	else if (c % 2 != 0)
	{
		for (int i = 0; i < c; ++i)
		{
			if (i % 2 == 0)
			{
				append(s, 'D', r - 1);
			}
			else
			{
				append(s, 'U', r - 1);
			}

			if (i < c - 1)
			{
				append(s, 'R', 1);
			}
		}
	}
	else
	{
		coord notVisit = findNotVisit(r, c);
		coord start = {.y = 0, .x = 0};
		coord end = {.y = r - 1, .x = c - 1};

		std::string s2;

		while (end.y - start.y > 1)
		{
			if (notVisit.y / 2 > start.y / 2)
			{
				append(s, 'R', c - 1);
				append(s, 'D', 1);
				append(s, 'L', c - 1);
				append(s, 'D', 1);
				start.y += 2;
			}
			if (notVisit.y / 2 < end.y / 2)
			{
				append(s2, 'R', c - 1);
				append(s2, 'D', 1);
				append(s2, 'L', c - 1);
				append(s2, 'D', 1);
				end.y -= 2;
			}
		}

		while (end.x - start.x > 1)
		{
			if (notVisit.x / 2 > start.x / 2)
			{
				append(s, 'D', 1);
				append(s, 'R', 1);
				append(s, 'U', 1);
				append(s, 'R', 1);
				start.x += 2;
			}
			if (notVisit.x / 2 < end.x / 2)
			{
				append(s2, 'D', 1);
				append(s2, 'R', 1);
				append(s2, 'U', 1);
				append(s2, 'R', 1);
				end.x -= 2;
			}
		}

		if (start.x == notVisit.x)
		{
			append(s, 'R', 1);
			append(s, 'D', 1);
		}
		else
		{
			append(s, 'D', 1);
			append(s, 'R', 1);
		}

		std::reverse(s2.begin(), s2.end());
		s.append(s2);
	}

	std::cout << s;

	return 0;
}