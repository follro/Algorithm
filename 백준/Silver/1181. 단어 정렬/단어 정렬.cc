#include <iostream>
#include <string>
#include <set>
#include <map>


int main()
{
	int n;
	
	std::cin >> n;
	std::map<int, std::set<std::string>> leg;
	
	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		leg[input.length()].insert(input);
	}

	for (auto mapIter : leg)
	{
		for (auto setIter : mapIter.second)
		{
			std::cout << setIter << "\n";
		}
	}


	return 0;
}




