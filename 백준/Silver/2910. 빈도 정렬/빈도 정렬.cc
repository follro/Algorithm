#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

int n, c;

std::vector<int> sequence;
std::map<int, int> counting;
std::vector<std::pair<int, int>> sortingTable;

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.second == b.second)
	{
		for (int data : sequence)
		{
			if (data == a.first)
				return true;
			else if (data == b.first)
				return false;
		}
	}
	
	return a.second > b.second;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> c;


	for (int i = 0; i < n; i++)
	{
		int input;
		std::cin >> input;

		std::map<int, int>::iterator it = counting.find(input);
		if (it == counting.end())
		{
			counting.insert({ input, 1 });
			sequence.push_back(input);
		}
		else
			(*it).second++;
	}

	for (auto data : counting)
		sortingTable.push_back(data);

	std::sort(sortingTable.begin(), sortingTable.end(), cmp);

	for (auto data : sortingTable)
	{
		for (int i = 0; i < data.second; i++)
			std::cout << data.first <<" ";
	}

	return 0;
}