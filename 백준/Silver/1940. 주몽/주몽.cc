#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n, m , count = 0;

	std::vector<int> container;

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;
		container.push_back(input);
	}
	
	std::sort(container.begin(), container.end());

	std::vector<int>::iterator front = container.begin();
	std::vector<int>::iterator back = container.end();
	back--;

	while (front != back)
	{
		int sum = (*front) + (*back);
		if (sum > m)
			back--;
		else if (sum < m)
			front++;
		else if (sum == m)
		{
			count++;
			front++;
		}
	}
	
	std::cout << count;

	return 0;
}

