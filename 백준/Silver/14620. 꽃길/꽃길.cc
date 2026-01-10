#include<iostream>
#include<vector>
int n;
int costs[104][104];
int visited[104][104];
int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, 1, 0 , -1 ,0 };
int minCost = 987654321;



void go(int start, int count, int cost)
{
	if (count == 3)
	{
		minCost = std::min(minCost, cost);
		return;
	}

	for (int i = start; i < n * n; i++)
	{
		int cy = i / n;
		int cx = i % n;
		
		int curCost = 0;
		int trigger = true;

		for (int j = 0; j < 5; j++) 
		{
			int ny = cy + dy[j];
			int nx = cx + dx[j];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
			{
				trigger = false;
				break;
			}
		}

		if (trigger)
		{
			for (int j = 0; j < 5; j++)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				visited[ny][nx] = 1;
				curCost += costs[ny][nx];
			}

			go(i + 1, count + 1, curCost + cost);

			for (int j = 0; j < 5; j++) 
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				visited[ny][nx] = 0;
			}
		}

	}

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	std::cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> costs[i][j];

	go(0, 0, 0);

	std::cout << minCost;
}