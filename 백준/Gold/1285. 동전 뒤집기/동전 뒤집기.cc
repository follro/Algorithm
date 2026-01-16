#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

int n;
std::vector<std::vector<bool>> coins;

int minNum = 987654321;

void colCheck(int select)
{
	for (int i = 0; i < n; i++)
	{
		if (!(select & (1 << i))) continue;

		for (int j = 0; j < n; j++)
			coins[i][j] = !coins[i][j];
	}
}

void rowCheck(int select)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int tureNum = 0;
		for (int j = 0; j < n; j++)
		{
			if (coins[j][i])
				tureNum++;
		}


		count += std::min(n - tureNum, tureNum);
	}

	minNum = std::min(count, minNum);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < n; i++)
	{
		std::string input;
		coins.push_back(std::vector<bool>());
		std::cin >> input;
		
		for (char v : input)
		{
			if (v == 'T')
				coins[i].push_back(false);
			else
				coins[i].push_back(true);
		}
	}

	for (int select = 1; select <= (1 << n); select++)
	{
		colCheck(select);

		rowCheck(select);

		colCheck(select);
	}

	std::cout << minNum;

	return 0;
}