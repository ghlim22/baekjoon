// <https://www.acmicpc.net/problem/20500>
// 20500번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define FACTOR (1000000007)
#define MAX_NUM (1515)

using namespace std;
static unsigned ll mods[MAX_NUM + 1][3];

signed main() {
	fastio;
	
	int input = 0;

	cin >> input;

	mods[1][0] = 0;
	mods[1][1] = 1;
	mods[1][2] = 1;
	for (int i = 2; i < input; ++i)
	{
		mods[i][0] = (mods[i - 1][1] % FACTOR + mods[i - 1][2] % FACTOR) % FACTOR;
		mods[i][1] = (mods[i - 1][0] % FACTOR + mods[i - 1][2] % FACTOR) % FACTOR;
		mods[i][2] = (mods[i - 1][0] % FACTOR + mods[i - 1][1] % FACTOR) % FACTOR;
	}
	cout << mods[input - 1][1] % FACTOR;

	return (0);
}