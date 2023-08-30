#include <iostream>
#include <queue>
int main(void)
{
	int n;
	int w;
	int	l;
	int	time = 0;
	int sum = 0;
	int	arr[1000];
	std::queue<int> bridge;

	std::cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		while (true)
		{
			if (bridge.size() == w)
			{
				sum -= bridge.front();
				bridge.pop();
			}
			if (sum + arr[i] <= l)
				break ;
			bridge.push(0);
			time++;
		}
		sum += arr[i];
		bridge.push(arr[i]);
		time++;
	}
	std::cout << time + w << std::endl;
	return 0;
}