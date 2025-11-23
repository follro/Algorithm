#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int h, w;
std::vector<std::vector<char>> map;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> h >> w;
	
	for (int i = 0; i < h; i++)
	{
		map.push_back(std::vector<char>());
		for (int j = 0; j < w; j++)
		{
			char input;
			std::cin >> input;
			map[i].push_back(input);
		}
	}

	for (int i = 0; i < h; i++)
	{
		int cPos = -1;
		int num;
		for (int j = 0; j < w; j++)
		{
			if (map[i][j] == 'c')
				cPos = j;

			if (cPos == -1)
				num = cPos;
			else
				num = j - cPos;

			std::cout << num << " ";
		}
		std::cout << "\n";
	}
}