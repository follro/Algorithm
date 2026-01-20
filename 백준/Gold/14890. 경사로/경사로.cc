	#include<iostream>
	#include<cmath>
	#include<algorithm>
	int n, L;
	int a[104][104], b[104][104];

	int ret;

	void go(int (&a)[104][104])
	{
		for (int i = 0; i < n; i++)
		{
			int cnt = 1;
			int j = 0;
			for (j = 0; j < n - 1; j++)
			{
				if (a[i][j] == a[i][j + 1]) cnt++;
				else if (a[i][j] + 1 == a[i][j + 1] && cnt >= L) cnt = 1;
				else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -L + 1;
				else break;
			}
			if (j == n - 1 && cnt >= 0) ret++;

		}
	}

	int main()
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL); std::cout.tie(NULL);

		std::cin >> n >> L;

		for (int i = 0; i < n * n; i++)
		{
			int y = i / n;
			int x = i % n;
			std::cin >> a[y][x];
			b[x][y] = a[y][x];
		}

		go(a);
		go(b);

		std::cout << ret;
	
		return 0;
	}