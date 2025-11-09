#include<iostream>
#include<string>
#include<vector>
#include<map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> numDictionary(n + 1);
	std::map<std::string, int> nameDictionary;

	
	for (int i = 1; i <= n; i++)
	{
		std::cin >> numDictionary[i];
		nameDictionary.insert(std::make_pair(numDictionary[i], i));
	}
	for (int i = 0; i < m; i++)
	{
		std::string input;
		std::cin >> input;

		if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'))
		{
			if (nameDictionary.find(input) != nameDictionary.end())
				std::cout << nameDictionary.find(input)->second << "\n";
		}
		else
			std::cout << numDictionary[std::stoi(input)] << "\n";
	}


	return 0;
}

