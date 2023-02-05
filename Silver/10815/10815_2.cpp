// https://www.acmicpc.net/problem/10815_2
// 10815_2번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int cards[500000];

static bool my_binary_search(int start, int end, int key)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (cards[mid] == key)
			return (true);
		else if (cards[mid] < key)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (false);
}

signed main() {
	fastio;

	int card_cnt = 0;
	int num_cnt = 0;

	cin >> card_cnt;
	for (int i = 0; i < card_cnt; ++i)
		cin >> cards[i];
	sort(cards, cards + card_cnt);

	cin >> num_cnt;
	for (int i = 0; i < num_cnt; ++i)
	{
		int num = 0;

		cin >> num;
		if (my_binary_search(0, card_cnt - 1, num))
			cout << 1;
		else
			cout << 0;
		cout << ' ';
	}

	return (0);
}