#include<iostream>

char map[21][21];
bool visited[21][21];
int visitedAlpah[28];
int n, m;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dfs(int cy, int cx)
{
	int maxDepth = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || visitedAlpah[map[ny][nx] - 'A']) continue;

		visited[ny][nx] = true;
		visitedAlpah[map[ny][nx] - 'A'] = true;

		maxDepth = std::max(maxDepth, dfs(ny, nx) + 1);

		visited[ny][nx] = false;
		visitedAlpah[map[ny][nx] - 'A'] = false;
	}

	return maxDepth;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			std::cin >> map[i][j];
			visited[i][j] = 0;
		}
	std::fill(&visitedAlpah[0], &visitedAlpah[0] + 28, 0);

	visited[0][0] = visitedAlpah[map[0][0] - 'A'] = true;

	std::cout << dfs(0, 0);



}
