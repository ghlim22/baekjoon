#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;
	int num = 0;

	cin >> num;
	for (int i = 2; i <= num; ++i)
	{
		if (num % i == 0){
			cout << i << '\n';
			num /= i;
			--i;
		}
	}

	return (0);
}