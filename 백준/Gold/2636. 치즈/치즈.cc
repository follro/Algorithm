#include <iostream>
#include <queue>
#include <set>

std::set<std::pair<int, int>> meltingCheese;

int table[100][100];
int testTable[100][100];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int m, n;
int count = 0, tIme = 0;

bool bfs(int x, int y)
{
	std::copy(&table[0][0], &table[0][0] + 10000, &testTable[0][0]);

	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(y, x));
	testTable[y][x] = 2;

	bool trigger = false;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || testTable[ny][nx] == 2) continue;
			if (testTable[ny][nx] == 1)
			{
				meltingCheese.insert({ ny, nx });
				trigger = true;
				continue;
			}
			else if (testTable[ny][nx] == 0)
				testTable[ny][nx] = 2;

			q.push({ ny, nx });
		}
	}

	
	return trigger;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> table[i][j];

	while(bfs(0, 0))
	{
		tIme++;
		for (auto cheese : meltingCheese)
		{
			table[cheese.first][cheese.second] = 0;
		}
		count = meltingCheese.size();
		meltingCheese.clear();

	}

	std::cout << tIme << "\n" << count;


	


	return 0;
}