#include<iostream>
#include<queue>
#define MAX 500001

int visited[2][MAX];

int n, k, meetT;
std::queue<std::pair<int,int>> q;

void bfs()
{
	std::fill(&visited[0][0], &visited[0][0] + MAX * 2, -1);
	visited[0][n] = 0;
	q.push({ n, 0 });// 위치와 시간 표시

	while (!q.empty())
	{
		int curPos = q.front().first;
		int curTime = q.front().second;
		q.pop();

		for (int nextPos : {curPos - 1, curPos + 1, curPos * 2})
		{
			int nextTime = curTime + 1;
			if (nextPos < 0 || nextPos >= MAX || visited[nextTime % 2][nextPos] != -1) continue;

			q.push({nextPos, nextTime});
			visited[nextTime % 2][nextPos] = visited[curTime % 2][curPos] + 1;
		}
	}

	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> k;
	bfs();
	for (int i = 0; i < MAX; i++) 
	{
		k += i; 

		if (k >= MAX) break; 

		if (visited[i % 2][k] != -1 && visited[i % 2][k] <= i)
		{
			std::cout << i;
			return 0;
		}
	}

	std::cout << "-1";
	return 0;
}