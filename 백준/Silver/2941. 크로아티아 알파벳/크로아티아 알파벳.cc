#include <iostream>

int main()
{
	std::string l;
	std::cin >> l;
	int cnt = 0;
	for (int i = 0; i < l.size();)
	{
		if (l.find("dz=", i) == i)
			i += 3;
		else if (l.find("c=", i) == i)
			i += 2;
		else if (l.find("c-", i) == i)
			i += 2;
		else if (l.find("d-", i) == i)
			i += 2;
		else if (l.find("lj", i) == i)
			i += 2;
		else if (l.find("nj", i) == i)
			i += 2;
		else if (l.find("s=", i) == i)
			i += 2;
		else if (l.find("z=", i) == i)
			i += 2;
		else
			i += 1;
		cnt++;
	}
	std::cout << cnt;
	return 0;
}