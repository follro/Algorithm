#include<iostream>
#include<vector>
#include<array>
#define MAX 987654321
int n;
int retValue = MAX;

int minValue[4];

int items[16][5];
std::vector<int> retSelected;
std::vector<int> curSelected;
bool check(std::array<int, 5>& curValue)
{
	for (int i = 0; i < 4; i++)
	{
		if (minValue[i] > curValue[i])
			return false;
	}

	return true;
}



void select(int idx, std::array<int, 5>& curValue)
{
	if (idx >= n)
	{
		if (check(curValue))
		{
			if (retValue > curValue[4])
			{
				retValue = curValue[4];
				retSelected = curSelected;
			}
			else if (retValue == curValue[4])
				if (retSelected.empty() || curSelected < retSelected)
					retSelected = curSelected;
		}
		return;
	}
	

	for (int i = 0; i < 5; i++)
		curValue[i] += items[idx][i];
	curSelected.push_back(idx);

	select(idx + 1, curValue);
	for (int i = 0; i < 5; i++)
		curValue[i] -= items[idx][i];

	curSelected.pop_back();
	select(idx + 1, curValue);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n;
	for (int i = 0; i < 4; i++)
		std::cin >> minValue[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			std::cin >> items[i][j];
	std::array<int, 5> values = {0,0,0,0,0};
	select(0, values);

	if (retValue == MAX)
	{
		std::cout << -1;
		return 0;
	}
	else
	{
		std::cout << retValue << "\n";

		for (auto value : retSelected)
			std::cout << value + 1 << " ";
	}
	return 0;
}