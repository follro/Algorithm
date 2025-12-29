#include <iostream>
#include <stack>
#include <queue>
#define MAX 200000

std::stack<int> way;
int n, k;
int before[MAX];
int visited[MAX];


void bfs()
{
	std::fill(&visited[0], &visited[0] + MAX, 0);
	std::fill(&before[0], &before[0] + MAX, -1);
	std::queue<int> q;
	visited[n] = 1;
	
	q.push(n);
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next < 0 || next >= MAX || visited[next]) continue;
		
			if (next == k)
			{
				visited[next] = visited[cur] + 1;
				before[next] = cur;
				return;
			}

			visited[next] = visited[cur] + 1;
			before[next] = cur;
			q.push(next);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> k;

	bfs();

	std::cout << visited[k] - 1 << "\n";

	int pos = k;
	way.push(k);

	while (pos != n)
	{
		way.push(before[pos]);
		pos = before[pos];
	}

	while (!way.empty())
	{
		std::cout << way.top() << " ";
		way.pop();
	}
}