#include <iostream>
#include<vector>
#include<algorithm>

int n, m, result = 100000000;
std::vector<std::vector<int>> chickenList;
std::vector<std::pair<int, int>> home, chicken;


void combi(int start, std::vector<int>& v)
{
	if (v.size() == m)
	{
		chickenList.push_back(v);
		return;
	}

	for (int i = start; i < chicken.size(); i++)
	{
		v.push_back(i);
		combi(i + 1, v);
		v.pop_back();
	}
	return;
}



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int input;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cin >> input;
			if (input == 1) home.push_back({ i, j });
			if (input == 2) chicken.push_back({ i, j });
		}
	}
	std::vector<int> selectedList;
	combi(0, selectedList);


	for (std::vector<int> selected : chickenList)
	{
		int ret = 0; 
		for (std::pair<int, int> hPos : home)
		{
			int minValue = 100000000;
			for (int idx : selected)
			{
				int dis = std::abs(hPos.first - chicken[idx].first) + std::abs(hPos.second - chicken[idx].second);
				minValue = std::min(minValue, dis);
			}
			ret += minValue;
		}
		result = std::min(result, ret);
	}

	std::cout << result;
}