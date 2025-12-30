#include<iostream>
#include<queue>
#define MAX 500001

int n, k, turn = 1;
int visited[2][MAX];
std::queue<int> q;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> k;
	if (n == k)
	{
		std::cout << "0";
		return 0;
	}
	q.push(n);
	visited[0][n];

	bool trigger = false;
	while (!q.empty())
	{
		k += turn;
		if (k >= MAX) break;
		if (visited[turn % 2][k])
		{
			trigger = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front();
			q.pop();
			for (int next : {cur - 1, cur + 1, cur * 2})
			{
				if (next < 0 || next >= MAX || visited[turn % 2][next]) continue;
				visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;
				if (next == k)
				{
					trigger = true;
					break;
				}
				q.push(next);
			}
			if (trigger) break;
		}

		if (trigger) break;
		turn++;
	}

	if (trigger)
		std::cout << turn;
	else
		std::cout << "-1";
	return 0;
}