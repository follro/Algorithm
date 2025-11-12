#include<iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n;


	while (std::cin >> n)
	{
		int	count = 0;
		long long rem = 0;
		while (true)
		{
			count++;
			rem = (rem * 10 + 1) % n;

			if (rem == 0) break;
		}

		std::cout << count << "\n";
	}
	return 0;
}

