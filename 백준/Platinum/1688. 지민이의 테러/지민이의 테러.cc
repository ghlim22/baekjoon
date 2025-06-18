#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

struct vec
{
	long long x;
	long long y;
	
	vec operator-(const vec &other) const
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

typedef std::pair<vec, vec> line;

int sign(long long n)
{
	if (n > 0)
		return 1;
	else if (n == 0)
		return 0;
	else
		return -1;
}

int ccw(const vec &p1, const vec &p2, const vec &p3)
{
	long long r = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
	return sign(r);
}

bool isOnLine(const line &l, const vec &p)
{
	if (ccw(l.first, l.second, p) != 0) {
		return false;
	}

	const vec &u = l.first;
	const vec &v = l.second;

	long long minX = std::min(u.x, v.x);
	long long maxX = std::max(u.x, v.x);
	long long minY = std::min(u.y, v.y);
	long long maxY = std::max(u.y, v.y);

	return (minX <= p.x) && (p.x <= maxX) && (minY <= p.y) && (p.y <= maxY);
}

int cross(const line &l1, const line &l2) 
{
	const vec &p1 = l1.first;
	const vec &p2 = l1.second;
	const vec &p3 = l2.first;
	const vec &p4 = l2.second;

	int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (r1 < 0 && r2 < 0) {
		return 1;
	} else {
		return 0;
	}
}

int solve(const vec &point, const std::vector<vec> &vertices)
{
	const vec pointOutside = {.x = 1, .y = INT_MAX};

	/* Check if the point is on border of the polygon */
	int N = vertices.size();
	for (int i = 0; i < N; ++i) {
		const vec &u = vertices[i];
		const vec &v = vertices[(i + 1) % N];
		if (isOnLine({u, v}, point)) {
			return 1;
		}
	}

	int counter = 0;
	line l2 = {pointOutside, point};
	for (int i = 0; i < N; ++i) {
		line l1 = {vertices[i], vertices[(i + 1) % N]};
		counter += cross(l1, l2);
	}

	return (counter % 2 == 1);
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<vec> vertices(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vertices[i].x >> vertices[i].y;
	}

	for (int i = 0; i < 3; ++i) {
		vec point;
		std::cin >> point.x >> point.y;
		std::cout << solve(point, vertices) << std::endl;
	}

	return 0;
}