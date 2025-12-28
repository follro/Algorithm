#include<iostream>
#include<queue>
#define MAX 300000

int n, k, cnt = 0;
int visited[MAX];

void bfs(int start)
{
	std::queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			cnt++; 
			break;
		}

		if (cur < 0) continue;

		int nextCount = visited[cur] + 1;
		int next1 = cur * 2;
		int next2 = cur - 1;
		int next3 = cur + 1;

		if (cur <= 100000 && visited[next1] >= nextCount)
		{
			q.push(next1);
			visited[next1] = nextCount;
		}

		if (next2 >= 0 && visited[next2] >= nextCount)
		{
			q.push(next2);
			visited[next2] = nextCount;
		}

		if (cur <= 100000 && visited[next3] >= nextCount)
		{
			q.push(next3);
			visited[next3] = nextCount;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == k) cnt++;
	}
	
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> k;

	std::fill(&visited[0], &visited[0] + MAX, MAX);
	
	bfs(n);

	std::cout << visited[k] << "\n" << cnt;
}