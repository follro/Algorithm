#include <iostream>
#include <queue>
#define INF 0x7FFFFFFF


long long a, b;

int BFS();

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> a >> b;


	
	
	std::cout << BFS();


}

int BFS( )
{
	std::queue<std::pair<long long, int>> datas;
	datas.push({ a, 1 });

	while (!datas.empty())
	{
		long long currentIndex = datas.front().first;
		int n = datas.front().second;
		datas.pop();

		if (b == currentIndex) return n;


		long long nextIndex1 = currentIndex * 2;
			
		long long nextIndex2 = currentIndex * 10 + 1;

		if (nextIndex1 <= b)
			datas.push({ nextIndex1, n + 1 });

		if (nextIndex2 <= b)
			datas.push({ nextIndex2, n + 1 });
	}

	return -1;
}
