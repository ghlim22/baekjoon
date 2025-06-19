
#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

struct vec;

int ccw(const vec &p1, const vec &p2, const vec &p3);

struct vec
{
	long long x;
	long long y;

	long long distance(const vec &other) const
	{
		long long x2 = other.x - x;
		long long y2 = other.y - y;
		x2 *= x2;
		y2 *= y2;
		return x2 + y2;
	}
	
	vec operator-(const vec &other) const
	{
		return {x - other.x, y - other.y};
	}

	bool operator<(const vec &other)
	{
		if (y == other.y) {
			return x < other.x;
		}
		return y < other.y;
	}

	bool operator==(const vec &other) 
	{
		return x == other.x && y == other.y;
	}

	bool operator<=(const vec &other)
	{
		return operator<(other) || operator==(other);
	}

	bool operator()(const vec &u, const vec &v) const 
	{
		int r = ccw(*this, u, v);
		if (r == 0) {
			return distance(u) < distance(v);
		} else {
			return r == 1;
		}
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

int main()
{
	int N;
	std::cin >> N;

	std::vector<vec> points(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> points[i].x >> points[i].y;
	}

	std::sort(points.begin(), points.end());

	vec p = points[0]; /* the point at the leftmost bottom */
	std::sort(points.begin(), points.end(), p);

	std::vector<vec> vertices;
	vertices.push_back(points[0]);
	vertices.push_back(points[1]);

	for (int i = 2; i < N; ++i) {
		while (vertices.size() >= 2 && ccw(vertices[vertices.size() - 2], vertices[vertices.size() - 1], points[i]) != 1) {
			vertices.pop_back();
		}
		vertices.push_back(points[i]);
	}

	std::cout << vertices.size() << std::endl;

	return 0;
}