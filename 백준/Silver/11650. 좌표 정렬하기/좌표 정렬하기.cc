#include <iostream>
#include <string>
#include <set>

int main()
{
	int n;
	int x, y;
	std::set<std::pair<int, int>> datas;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> x >> y;
		datas.insert({ x, y });
	}

	for (auto xy : datas)
	{
		std::cout << xy.first << " " << xy.second << "\n";
	}

	return 0;
}



