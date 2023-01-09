#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	int N;
	int K;

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		q.push(i);
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; ++i)
		{
			int tmp = q.front();
			q.push(tmp);
			q.pop();
		}
		int res = q.front();
		q.pop();
		cout << res;
		if (!q.empty())
			cout << ", ";
		else
			cout << ">";
	}
	return 0;
}