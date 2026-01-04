#include <iostream>
#include <queue>

int n, m, turn = 0;
char map[1501][1501];
bool swanVisited[1501][1501];
bool waterVisited[1501][1501];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
std::queue<std::pair<int, int>> swanQ;

std::queue<std::pair<int, int>> waterQ;

std::pair<int, int> swanStart;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> map[i][j];
			swanVisited[i][j] = waterVisited[i][j] = 0;

			if (map[i][j] != 'X')
			{
				waterQ.push({ i,j });
				waterVisited[i][j] = true;
			}
			
			if (map[i][j] == 'L')
				swanStart = { i,j };
			
		}
	}


	bool trigger = false;
	swanQ.push(swanStart);
	swanVisited[swanStart.first][swanStart.second] = true;
	while (!trigger)
	{
		std::queue<std::pair<int, int>> swanTempQ;
		std::queue<std::pair<int, int>> waterTempQ;
		
		while (!swanQ.empty())
		{
			int cy = swanQ.front().first;
			int cx = swanQ.front().second;
			swanQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + cy;
				int nx = dx[i] + cx;

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || swanVisited[ny][nx]) continue;

				swanVisited[ny][nx] = true;

				if (map[ny][nx] == 'X')
					swanTempQ.push({ ny,nx });
				else if (map[ny][nx] == '.')
					swanQ.push({ ny,nx });
				else if (map[ny][nx] == 'L')
				{
					trigger = true;
					break;
				}
			}
			if (trigger) break;
		}

		if (trigger) break;
		swanQ = swanTempQ;

		while (!waterQ.empty())
		{
			int cy = waterQ.front().first;
			int cx = waterQ.front().second;
			waterQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + cy;
				int nx = dx[i] + cx;

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || waterVisited[ny][nx]) continue;

				waterVisited[ny][nx] = true;
				if (map[ny][nx] == 'X')
				{
					map[ny][nx] = '.';
					waterTempQ.push({ ny, nx });
				}
			}
		}

		waterQ = waterTempQ;
		turn++;
	}

	std::cout << turn;
}