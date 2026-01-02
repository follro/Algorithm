#include<iostream>
#include<queue>


int n, m, turn = 0;
int targetX, targetY;
int startX, startY;

char map[304][304];
int visited[304][304];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

std::queue<std::pair<int, int>> q0;
std::queue<std::pair<int, int>> q1;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;
	std::cin >> startY >> startX >> targetY >> targetX;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			std::cin >> map[i][j];
			visited[i][j] = 0;
		}
	q1.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q1.empty())
	{
		turn++;
		while (!q1.empty())
		{
			q0.push(q1.front());
			q1.pop();
		}

		while (!q0.empty())
		{
			int curY = q0.front().first;
			int curX = q0.front().second;
			q0.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];

				if (nextY < 1 || nextY > n || nextX < 1 || nextX > m || visited[nextY][nextX]) continue;

				switch (map[nextY][nextX])
				{
				case '0':
					q0.push({ nextY, nextX });
					visited[nextY][nextX] = 1;
					break;
				case '1':
					q1.push({ nextY, nextX });
					visited[nextY][nextX] = 1;
					break;
				case '#':
					std::cout << turn;
					return 0;
				}

			}

		}
	}

	return 0;
}