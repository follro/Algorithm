#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>

int row, col;
char map[50][50];
int visited[50][50];
int maxDis = 0;
std::vector<std::pair<int, int>> lands;
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { 1, 0, -1, 0 };


int bfs(std::pair<int, int> start)
{
	std::queue<std::pair<int, int>> q;
	q.push(start);
	std::fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
	visited[start.first][start.second] = 1;
	int result = 0;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		result = std::max(result, visited[curY][curX]);

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dirY[i];
			int nextX = curX + dirX[i];

			if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col) continue;
			if (map[nextY][nextX] == 'W') continue;
			if (visited[nextY][nextX]) continue;

			visited[nextY][nextX] = visited[curY][curX] + 1;
			q.push({ nextY, nextX });
		}
	}

	return result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> row >> col;

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
		{
			std::cin >> map[r][c];
			visited[r][c] = 0;
			if (map[r][c] == 'L') lands.push_back({ r,c });
		}
	
	for (auto land : lands)
		maxDis = std::max(maxDis, bfs(land));

	std::cout << maxDis -1 ;

}