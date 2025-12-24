#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

int land[50][50];
int visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, l, r, cnt = 0;


int dfs(int y, int x, std::vector<std::pair<int,int>>& alliance)
{
	visited[y][x] = 1;
	alliance.push_back({ y, x });
	int ret = land[y][x];
	int dif = -1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= n || nx < 0 || ny >= n || ny < 0 || visited[ny][nx]) continue;
		dif = std::abs(land[y][x] - land[ny][nx]);
		if (dif < l || dif > r) continue;

		ret += dfs(ny, nx, alliance);
	}

	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cin >> land[i][j];
		}

	while (true)
	{
		std::fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
		bool isMoved = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					std::vector<std::pair<int, int>> clan;
					int ret = dfs(i, j, clan);
					if (clan.size() > 1)
					{
						isMoved = true;
						int avg = (int)(ret / clan.size());
						for (auto pos : clan)
							land[pos.first][pos.second] = avg;
					}

				}
			}

		if (!isMoved) break;
		cnt++;
	}

	std::cout << cnt;
}