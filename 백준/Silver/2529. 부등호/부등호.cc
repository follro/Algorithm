#include<iostream>
#include<cstring>
#include <algorithm>

int k;
std::string maxValue, minValue;
bool visited[10];
char inequality[9];

void dfs(std::string& value, int index)
{
	if (index == k + 1) 
	{ 
		if (minValue == "" || value < minValue) minValue = value;
		if (maxValue == "" || value > maxValue) maxValue = value;
		return;
	}

	for(int i = 0; i < 10; i++)
	{
		if (visited[i]) continue;

		if (index > 0)
		{
			int cur = i + '0';
			int prev = value[index - 1];

			if (inequality[index - 1] == '>')
			{
				if (prev <= cur) continue;
			}
			else if (inequality[index - 1] == '<')
			{
				if (prev >= cur) continue;
			}
		}

		visited[i] = true;
		value.push_back(i + '0');

		dfs(value, index + 1);
		
		visited[i] = false;
		value.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> k;

	for (int i = 0; i < k; i++)
		std::cin >> inequality[i];

	std::string ret = "";
	dfs(ret, 0);

	std::cout << maxValue << "\n" << minValue;
}

