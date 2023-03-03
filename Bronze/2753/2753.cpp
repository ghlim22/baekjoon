// https://www.acmicpc.net/problem/2753
// 2753번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;
	int year, res;

	cin >> year;
	res = (year % 4 == 0) ^ (year % 100 == 0) ^ (year % 400 == 0);
	cout << res;

	return (0);
}