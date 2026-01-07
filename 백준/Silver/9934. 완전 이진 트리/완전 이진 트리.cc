#include <iostream>
#include <vector>
int k, num;
std::vector<int> map;
std::vector<std::vector<int>> nodes;

void TreeSetter(int level , int start, int end)
{
	if (level >= k || start > end) return;

	int mid = (start + end) / 2;
	nodes[level].push_back(map[mid]);

	TreeSetter(level + 1, start, mid -1);
	TreeSetter(level + 1, mid + 1, end);

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);


	std::cin >> k;
	num = (1 << k) - 1;
	
	for (int i = 0; i < num; i++)
	{
		int input;
		std::cin >> input;
		map.push_back(input);
	}

	nodes = std::vector<std::vector<int>>(k, std::vector<int>());
	TreeSetter(0, 0, num - 1);

	for (const auto& level : nodes)
	{
		for (int value : level)
		{
			std::cout << value << " ";
		}
		std::cout << "\n";
	}



}