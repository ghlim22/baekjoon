// <https://www.acmicpc.net/problem/7568>
// 7568번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

typedef struct s_student
{
	int num;
	int weight;
	int height;
	int rank;
}	t_student;

static t_student arr[100];

signed main()
{
	fastio;
	int student_cnt;
	int rank;

	cin >> student_cnt;
	for (int i = 0; i < student_cnt; ++i)
	{
		int weight;
		int height;

		cin >> weight >> height;
		arr[i].num = i;
		arr[i].weight = weight;
		arr[i].height = height;
		arr[i].rank = 1;
	}
	for (int i = 0; i < student_cnt; ++i)
	{
		for (int j = 0; j < student_cnt; ++j)
		{
			if (i == j)
				continue;
			if (arr[j].height > arr[i].height && arr[j].weight > arr[i].weight)
				arr[i].rank++;
		}
		cout << arr[i].rank << ' ';
	}
	return (0);
}