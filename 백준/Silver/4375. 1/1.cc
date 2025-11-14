#include<iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n;

	while (std::cin >> n)
	{
		int rem = 0;
		int count = 1;
		while (true)
		{
			rem = ((rem * 10 % n) + 1) % n;
			if (rem == 0) break;
			count++;
		}
		std::cout << count << "\n";
	}


	return 0;
}

