#include<iostream>
#include<vector>
#include<string>

int n, count, maxCount =0;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
//std::vector<std::vector<int>> map;
//std::vector<std::vector<bool>> visited;
int map[101][101];
int visited[101][101];


void dfs(int height, std::pair<int, int> curPos)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + curPos.first;
		int nx = dx[i] + curPos.second;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (visited[ny][nx]) continue;

		if ((map[ny][nx] - height) > 0)
		{
			visited[ny][nx] = 1;
			dfs(height, { ny, nx });
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;
	int maxValue = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
			
			if (maxValue < map[i][j]) maxValue = map[i][j];
		}
	}
	
	

	for (int height = 0; height <= maxValue; height++)
	{
		count = 0;
		std::fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if ((map[j][k] > height) && !visited[j][k])
				{
					++count;
					dfs(height, {j, k});
				}
			}
		}

		if (count > maxCount) maxCount = count;
	}
	
	std::cout << maxCount;

	return 0;
}