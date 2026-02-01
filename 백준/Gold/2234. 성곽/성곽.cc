#include <iostream>
#include <algorithm>
#include <vector>
int n, m;
int roomCnt;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int map[52][52];
int visited[52][52];

std::vector<int> groupSize;
int maxSize;

int dfs(int y, int x, int cnt)
{
	if (visited[y][x])
		return 0;
	visited[y][x] = cnt;
	int ret = 1;

	for (int i = 0; i < 4; i++)
	{
		if (!(map[y][x] & (1 << i)))
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			ret += dfs(ny, nx, cnt);
		}
	}

	return ret;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			std::cin >> map[i][j];

	//std::fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);

	int cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				cnt++;
				groupSize.push_back(dfs(i, j, cnt));
				maxSize = std::max(groupSize.back(), maxSize);
			}
		}

	std::cout << groupSize.size() << '\n';
	std::cout << maxSize << '\n';

	//벽 부숴보는 로직

	int biggist = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + 1 < m)
			{
				int a = visited[i + 1][j];
				int b = visited[i][j];

				if(a!= b)
					biggist = std::max( biggist , groupSize[a - 1] + groupSize[b - 1]);
			}
			if (j + 1 < n)
			{
				int a = visited[i][j + 1];
				int b = visited[i][j];
				if (a != b)
					biggist = std::max(biggist, groupSize[a - 1] + groupSize[b - 1]);
			}
		}
	}

	std::cout << biggist;
	return 0;

}