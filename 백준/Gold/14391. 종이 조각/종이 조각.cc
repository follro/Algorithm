#include <iostream>
#include <algorithm>

int map[4][4];

int n, m;
int ret;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		std::string line;
		std::cin >> line;
		for (int j = 0; j < m; j++) 
			map[i][j] = line[j] - '0'; 
	}

	for (int i = 0; i < (1 << (n * m)); i++)
	{
		int sum = 0;

		for (int y = 0; y < n; y++)
		{
			int cur = 0;
			for (int x = 0; x < m; x++)
			{
				int k = y * m + x;
				if ((i & (1 << k)) == 0)
					cur = cur * 10 + map[y][x];
				else
				{
					sum += cur;
					cur = 0;
				}
			}

			sum += cur;
		}

		for (int x = 0; x < m; x++)
		{
			int cur = 0;
			for (int y = 0; y < n; y++)
			{
				int k = y * m + x;
				if ((i & (1 << k)) != 0)
					cur = cur * 10 + map[y][x];
				else
				{
					sum += cur;
					cur = 0;
				}
			}

			sum += cur;
		}

		ret = std::max(sum, ret);
	}

	std::cout << ret;

	return 0;
}