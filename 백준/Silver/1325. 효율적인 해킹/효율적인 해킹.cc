#include<iostream>
#include<vector>
#include<algorithm>

int n, m;
int a, b;
std::vector<int> values;
std::vector<std::vector<int>> computers;

//방문 가능한 것들의 갯수 - 이미 방문한 것 
int dfs(int curNum, std::vector<bool>& visitor)
{
	visitor[curNum] = true;

	int ret = 1;
	for (int data : computers[curNum])
	{
		if (!visitor[data])
			ret += dfs(data, visitor);
	}

	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;
	
	computers.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		std::cin >> a >> b;
		
		computers[b].push_back(a);
	}
	values.resize(n + 1);
	std::vector<bool> visitor(n + 1);

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		std::fill(visitor.begin(), visitor.end(), false);
		values[i] = dfs(i, visitor);

		if (max < values[i]) max = values[i];
	}


	for (int i = 1; i <= n; i++)
	{
		if (values[i] == max) std::cout << i << " ";
	}
	
	
	

	


	return 0;
}