#include<iostream>
#include<queue>
#define MAX 100000

int n, k;
int visited[MAX+4];
int cnt[MAX + 4];


void bfs(int start)
{
	if (n == k)
	{
		visited[k] = 1;
		cnt[k] = 1;
		return;
	}
	std::fill(&visited[0], &visited[0] + MAX, 0);
	std::queue<int> q;
	q.push(start);
	visited[start] = 1;
	cnt[start] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next < 0 || next > MAX) continue;

			if (!visited[next])
			{
				visited[next] = visited[cur] + 1;
				q.push(next);
				cnt[next] += cnt[cur];
			}
			else if (visited[next] == visited[cur] + 1)
				cnt[next] += cnt[cur];
		}

	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> k;

	bfs(n);

	std::cout << visited[k] - 1 << "\n" << cnt[k];
}