#include <iostream>
#include <vector>
// 부모에서 제거를 안해주면 안됨.

int n;
int target;
int head;

std::vector<std::vector<int>> nodes;

int dfs(int curNum)
{
	int child = 0;
	int ret = 0;
	for (auto node : nodes[curNum])
	{
		if (node != target)
		{
			ret += dfs(node);
			child++;
		}

	}

	if (child == 0) return 1;
	else return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;
	nodes.resize(n);

	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;
		
		if (input == -1) { head = i; continue; }

		nodes[input].push_back(i);
	}

	std::cin >> target;

	nodes[target].clear();
	if (target != head)
		std::cout << dfs(head);
	else
		std::cout << "0";
	

	return 0;
}