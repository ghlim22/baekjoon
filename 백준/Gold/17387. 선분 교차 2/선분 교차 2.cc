#include <algorithm>
#include <iostream>

struct vec
{
	long long x;
	long long y;
	vec operator-(const vec &other)
	{
		return {x - other.x, y - other.y};
	}
	bool operator<(const vec &other)
	{
		if (x == other.x) {
			return y < other.y;
		}
		return x < other.x;
	}
	bool operator==(const vec &other) 
	{
		return x == other.x && y == other.y;
	}
	bool operator<=(const vec &other)
	{
		return operator<(other) || operator==(other);
	}
};

long long ccw(vec u, vec v, vec w)
{
	vec p = v - u;
	vec q = w - v;
	return p.x * q.y - p.y * q.x;
}

int sign(long long x) 
{
	if (x < 0)
		return -1;
	else if (x == 0)
		return 0;
	else 
		return 1;
}

int main()
{
	vec p[5];

	for (int i = 1; i <= 4; ++i) {
		std::cin >> p[i].x >> p[i].y;
	}

	long long p1p2p3 = ccw(p[1], p[2], p[3]);
	long long p1p2p4 = ccw(p[1], p[2], p[4]);
	int r1 = sign(p1p2p3) * sign(p1p2p4);
	
	long long p3p4p1 = ccw(p[3], p[4], p[1]);
	long long p3p4p2 = ccw(p[3], p[4], p[2]);
	int r2 = sign(p3p4p1) * sign(p3p4p2);

	int result = 0;
	if (r1 == 0 && r2 == 0) {
		std::sort(p + 1, p + 3);
		std::sort(p + 3, p + 5);
		if (p[3] <= p[2] && p[1] <= p[4]) {
			result = 1;	
		}
	} else if (r1 <= 0 && r2 <= 0) {
		result = 1;
	}

	std::cout << result << std::endl;

	return 0;
}
