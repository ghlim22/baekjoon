#include <iostream>
#include <queue>

static int n, w, l;
static std::queue<int> trucks;
static int	bridge[100];

/* except the front truck */
int get_bridge_total_weight(void)
{
	int ret = 0;
	for (int i = 0; i < w - 1; ++i)
		ret += bridge[i];
	return ret;
}

void	move_trucks(int new_truck)
{
	for (int i = w - 1; i >= 1; --i)
		bridge[i] = bridge[i - 1];
	bridge[0] = new_truck;
}

int main(void)
{
	std::cin >> n >> w >> l;
	for (int i = 0; i < n; ++i)
	{
		int truck_weight;
		std::cin >> truck_weight;
		trucks.push(truck_weight);
	}
	int time = 0;
	while (!trucks.empty())
	{
		int front_truck = trucks.front();
		if (get_bridge_total_weight() + front_truck <= l)
		{
			move_trucks(front_truck);
			trucks.pop();
		}
		else
		{
			move_trucks(0);
		}
		time++;
	}
	while (get_bridge_total_weight() > 0)
	{
		move_trucks(0);
		time++;
	}
	std::cout << time + 1 << std::endl;
	return 0;
}
