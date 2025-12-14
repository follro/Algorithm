#include<iostream>
#include<string>
#include<queue>
#include<vector>

int map[8][8];
int testMap[8][8];

int n, m, maxNum = 0;
std::queue<std::pair<int, int>> q;
std::vector<std::pair<int, int>> virusPos;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1 , 0, -1, 0 };

int bfs()
{
	std::copy(&map[0][0], &map[0][0] + 64, &testMap[0][0]); 

	int curNum = 0;
	for (auto pos : virusPos)
		q.push(pos);

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (testMap[ny][nx] != 0) continue;

			testMap[ny][nx] = 2;
			q.push(std::make_pair(ny, nx));
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (testMap[i][j] == 0) curNum++;

	return curNum;
}

void dfsBuildWall(int startPos, int count)
{
	if (count == 3)
	{
		int data = bfs();
		if (maxNum < data) maxNum = data;
		return;
	}

	for (int i = startPos; i < n * m; i++)
	{
		int y = i / m; 
		int x = i % m; 

		if (map[y][x] == 0)
		{
			map[y][x] = 1;
			dfsBuildWall(i + 1, count + 1);
			map[y][x] = 0;
		}
	}
}


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
			if (map[i][j] == 2) virusPos.push_back(std::make_pair(i, j));
		}
	}

	dfsBuildWall(0, 0);

	std::cout << maxNum;
	

	return 0;
}