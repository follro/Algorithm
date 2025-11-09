#include<iostream>
#include<limits>
#include<vector>
const int minValue = std::numeric_limits<int>::min();

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k, input;
	int maxValue = minValue;

	std::cin >> n >> k;
	std::vector<int> table(n+1);

	table[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> input;
		table[i] = table[i - 1] + input;
		
		if (i >= k && (table[i] - table[i - k]) > maxValue)
		{
			maxValue = table[i] - table[i - k];
		}
	}



	std::cout << maxValue;


	return 0;
}

