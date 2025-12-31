#include<iostream>
#include<queue>

int n, m;
char map[301][301];
int visited[301][301];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int juX, juY;
int doroboX, doroboY;
int turn = 0;
std::queue<std::pair<int, int>> q;


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	std::cin >> n >> m;
	std::cin >> juY >> juX >> doroboY >> doroboX;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> map[i][j];
	
	map[juY][juX] = '*';
	map[doroboY][doroboX] = '#';

	q.push({ juY, juX });
	std::fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
	visited[juY][juX] = 1;

	while (true)
	{
		turn++;
		bool flag = false;
		std::queue<std::pair<int, int>> nextQ;

		while(!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];

				if (ny < 1 || nx < 1 || ny > n || nx > m || visited[ny][nx]) continue;

				visited[ny][nx] = 1;

				if (map[ny][nx] == '1')
					nextQ.push({ ny, nx });

				switch (map[ny][nx])
				{
				case '0':
					q.push({ ny, nx });
					break;
				case '1':
					nextQ.push({ ny, nx });
					break;
				case '#':
					flag = true;
					break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (flag) break;

		q = nextQ;
	}

	std::cout << turn;
}
