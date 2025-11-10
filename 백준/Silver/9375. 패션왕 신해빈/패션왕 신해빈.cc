#include<iostream>
#include<string>
#include<map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int testCase;
	int n;

	std::cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		std::cin >> n;
		std::map<std::string, int> clothes;

		for (int i = 0; i < n; i++)
		{
			std::string style;
			std::string name;

			std::cin >> name >> style;

			if (clothes.find(style) != clothes.end())
				clothes[style]++;
			else
				clothes.insert({ style, 1 });
		}


		int result = 1;
		for (std::pair<std::string, int> value : clothes)
			result *= (value.second + 1);

		result -= 1;
		
		std::cout << result << "\n";
	}

	
	return 0;
}

