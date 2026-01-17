#include<iostream>
#include<string>
#include<algorithm>
#define MAX 987654321;
int n;
int map[24];
int retCnt = MAX;


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		for (int j = 0; j < n; j++)
		{
			if (input[j] == 'T')
				map[i] += (1 << j);
		}
	}

	for (int i = 0; i <= (1 << (n - 1)); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				map[j] = ~map[j];
		}

		int cnt = 0;
		//열검사
		for (int j = 0; j < n; j++)
		{
			int colCnt = 0;
			for (int k = 0; k < n; k++)
			{
				if (map[k] & (1 << j))
					colCnt++;
			}
			cnt += std::min(colCnt, n - colCnt);
		}
		
		retCnt = std::min(retCnt, cnt);

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j) )
				map[j] = ~map[j];
		}
	}

	std::cout << retCnt;

	return 0;
}