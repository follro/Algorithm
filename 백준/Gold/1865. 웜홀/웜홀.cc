#include <iostream>
#include <vector>
#include <tuple>
#define INF 0x7FFFFFFF


//n은 노드 m은 양방향 w는 단방향

int n, m, w;
int tc;

bool BellmanFord(std::vector<std::tuple<int, int, int>>& loads);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> tc;

	for (int testcase = 0; testcase < tc; testcase++)
	{
		std::cin >> n >> m >> w;
		std::vector<std::tuple<int, int, int>> loads;

		//load
		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			std::cin >> s >> e >> t;
			s -= 1;
			e -= 1;

			loads.push_back({ s, e, t });
			loads.push_back({ e, s, t });
		}

		//wormHole
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			std::cin >> s >> e >> t;
			s -= 1;
			e -= 1;
			t *= -1;
			loads.push_back({ s, e, t });
		}

		if (BellmanFord(loads))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}


}

bool BellmanFord(std::vector<std::tuple<int, int, int>>& loads)
{

	int* minWeight = new int[n];

	for (int i = 0; i < n; i++)
		minWeight[i] = 0;

	

	for(int i = 0; i < n;i++)
	{
		for (int j = 0; j < loads.size(); j++)
		{
			int from, to, cost;
			std::tie( from, to, cost ) = loads[j];

			if (minWeight[to] > minWeight[from] + cost)
			{
				minWeight[to] = minWeight[from] + cost;

				if (i == n - 1)
					return true;
			}
		}
	}


	delete[] minWeight;
	return false;
}
