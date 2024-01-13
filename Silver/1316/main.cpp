#include <iostream>

int main(void)
{
	int n;
	int ans = 0;
	std::string s;

	std::cin >> n;
	while (n--)
	{
		bool flag = true;
		int arr[26] = {0, };
		std::cin >> s;
		for (int i = 0; i < s.length(); ++i)
		{
			int idx = s[i] - 'a';
			if (arr[idx] == 0)
			{
				arr[idx]++;
			}
			else if (s[i - 1] != s[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}
	std::cout << ans << std::endl;

	return 0;
}
