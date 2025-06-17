#include <algorithm>
#include <iostream>

struct vector
{
	long long  x;
	long long y;
	vector operator-(vector &other)
	{
		return {x - other.x, y - other.y};
	}
};

long long calculateArea(const vector &u, const vector &v)
{
	return (u.x * v.y) - (u.y * v.x);
}

int main()
{
	int N;
	std::cin >> N;

	vector p1, p2;
	std::cin >> p1.x >> p1.y >> p2.x >> p2.y;

	vector u = p2 - p1;
	long long sum = 0;
	for (int i = 2; i < N; ++i) {
		vector point;
		std::cin >> point.x >> point.y;
		vector v = point - p1;
		sum += calculateArea(u, v);
		u = v;
	}
	
	sum = std::abs(sum);
	std::printf("%lld.%lld\n", sum / 2, (sum & 1) * 5);

	return 0;
}