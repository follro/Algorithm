#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int n;

std::vector<std::vector<char>> map;

std::string quard(std::pair<int, int> startPos, int size)
{
	if (size == 1)
		return std::string(1,map[startPos.first][startPos.second]);
	
	std::string result ="";

	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (map[startPos.first][startPos.second] != map[startPos.first + i][startPos.second + j])
			{
				int nextSize = size / 2;
				result += "(";
				result += quard(startPos, nextSize);
				result += quard({ startPos.first,			startPos.second + nextSize }, nextSize);
				result += quard({ startPos.first + nextSize, startPos.second }, nextSize);
				result += quard({ startPos.first + nextSize, startPos.second + nextSize }, nextSize);
				result += ")";
				return result;
			}
		} 

	return std::string(1, map[startPos.first][startPos.second]);
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;

	map = std::vector<std::vector<char>>(n, std::vector<char>(n, 0));

	std::string input;
	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = input[j];
		}
	}
	std::cout << quard({ 0, 0 }, n);

	
	return 0;
}