#include <iostream>
#include <vector>
// 부모에서 제거를 안해주면 안됨.

int n;
int target;
int head;
int count= 0;

std::vector<std::vector<int>> nodes;

void dfs(int curNum)
{
	if (nodes[curNum].empty() || (nodes[curNum][0] == target && nodes[curNum].size() == 1))
	{
		count++;
		return;
	}


	for (auto node : nodes[curNum])
	{
		if(node != target)
			dfs(node);
	}
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
	if(target != head)
		dfs(head);

	std::cout << count;
	

	return 0;
}