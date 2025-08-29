#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 98765432

int n, m, x;
int result = 0;


std::vector<std::pair<int, int>> weights[1002];


int Dijkstra(int startIndex, int targetIndex);

int main()
{

	std::cin >> n >> m >> x;
	
	x -= 1;
	

	for (int i = 0; i < m; i++)
	{
		int a, b, weight;
		std::cin >> a >> b >> weight;

		weights[a - 1].push_back(std::make_pair(weight, b - 1));
	}

	for (int i = 0; i < n; i++)
	{
		int currentResult = 0;

		currentResult = Dijkstra(i, x);

		currentResult += Dijkstra(x, i);

		if (currentResult > result)
			result = currentResult;
	}

	std::cout << result;
	return 0;
}

int Dijkstra(int startIndex, int targetIndex)
{
	std::vector<int> dst;
	for (int i = 0; i < n; i++)
		dst.push_back(INF);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({0,startIndex});

	dst[startIndex] = 0;

	while (!pq.empty())
	{
		int currentNode = pq.top().second;
		int currentWeight = pq.top().first;
		pq.pop();

		if (currentNode == targetIndex)
			return dst[currentNode];

		for (int i = 0; i < weights[currentNode].size(); i++)
		{
			int nextNode = weights[currentNode][i].second;
			int nextWeight = weights[currentNode][i].first + currentWeight;

			if (nextWeight < dst[nextNode])
			{
				dst[nextNode] = nextWeight;
				pq.push({nextWeight, nextNode});
			}

		}
	}


	

}
