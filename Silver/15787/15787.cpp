// <https://www.acmicpc.net/problem/15787>
// 15787번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static unsigned int train[100001];
static bool is_identical[100001];

static void command_one(int train_idx, int seat_idx)
{
	train[train_idx] |= (1 << seat_idx);
}

static void command_two(int train_idx, int seat_idx)
{
	train[train_idx] &= ~(1 << seat_idx);
}

static void command_three(int train_idx)
{
	train[train_idx] &= (1 << 21) - 2;
	train[train_idx] <<= 1;
	train[train_idx] &= (1 << 21) - 2;
}

static void command_four(int train_idx)
{
	train[train_idx] &= (1 << 21) - 2;
	train[train_idx] >>= 1;
	train[train_idx] &= (1 << 21) - 2;
}


signed main() {
	fastio;

	int train_cnt = 0;
	int command_cnt = 0;
	int ans = 0;

	cin >> train_cnt >> command_cnt;
	while (command_cnt--)
	{
		int command_num;
		int train_idx;
		int seat_idx;

		cin >> command_num;
		if (command_num <= 2)
			cin >> train_idx >> seat_idx;
		else
			cin >> train_idx;
		switch (command_num)
		{
		case 1:
			command_one(train_idx, seat_idx);
			break;
		case 2:
			command_two(train_idx, seat_idx);
			break;
		case 3:
			command_three(train_idx);
			break;
		case 4:
			command_four(train_idx);
		default:
			break;
		}
	}	
	for (int i = 1; i <= train_cnt; ++i)
	{
		if (!is_identical[i])
		{
			ans++;
			for (int j = i + 1; j <= train_cnt; ++j)
			{
				if (train[i] == train[j])
				{
					is_identical[j] = true;
				}
			}
		}
	}
	cout << ans;

	return (0);
}