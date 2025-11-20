#include<iostream>
#include<queue>
#include<vector>
#include<string>
const int WayNum = 4;

int n, m;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

std::vector<std::vector<int>>  map;
std::vector<std::vector<int>> visited;

void bfs(std::pair<int, int> startPos, std::pair<int, int> endPos)
{
	std::queue<std::pair<int, int>> q;
	visited[startPos.first][startPos.second] = 1;
	q.push(startPos);

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		if (curY == endPos.first && curX == endPos.second) return;
		
		for (int i = 0; i < WayNum; i++)
		{
			int nextY = dy[i] + curY;
			int nextX = dx[i] + curX;

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || !map[nextY][nextX] || visited[nextY][nextX]) continue;

			visited[nextY][nextX] = visited[curY][curX] + 1;
			q.push({ nextY, nextX });
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::string input;
	
	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		map.push_back(std::vector<int>());
		visited.push_back(std::vector<int>(m , 0));

		for (int j = 0; j < m; j++)
			map[i].push_back(input[j] - '0');
	}

	bfs({ 0, 0 }, { n - 1, m - 1 });

	std::cout << visited[n - 1][m - 1] << "\n";


	return 0;
}