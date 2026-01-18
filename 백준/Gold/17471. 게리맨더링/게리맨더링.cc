#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 987654321

int n, ret = MAX;
int population[11], map[11], visited[11];

std::vector<std::vector<int>> nodes;

std::pair<int,int> dfs(int here, int value)
{
	visited[here] = 1;
	std::pair<int, int> ret = { 1, population[here] };
	for (int next : nodes[here])
	{
		if (map[next] != value) continue;
		if (visited[next]) continue;

		std::pair<int, int> temp = dfs(next, value);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;
	
	for (int i = 0; i < n; i++)
		std::cin >> population[i];

	for (int i = 0; i < n; i++)
	{
		int cnt, temp;
		std::cin >> cnt;
		nodes.push_back(std::vector<int>());

		for (int j = 0; j < cnt; j++)
		{
			std::cin >> temp;
			nodes[i].push_back(temp - 1);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		std::fill(map, map + 11, 0);
		std::fill(visited, visited + 11, 0);
		int blue = 0 , red = 0;
		
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				map[j] = 1;
				blue = j;
			}
			else
				red = j;
		}

		std::pair<int,int> v1 = dfs(blue, 1);
		std::pair<int,int> v2 = dfs(red, 0);
		
		if (v1.first + v2.first != n) continue;

		ret = std::min(ret, std::abs(v1.second - v2.second));
	}

	if (ret != MAX) std::cout << ret;
	else
		std::cout << -1;

	
}
