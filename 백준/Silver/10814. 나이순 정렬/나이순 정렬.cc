#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
	std::multimap<int, std::string> multi;

	int n;
	int age;
	std::string name;
	
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> age >> name;
		multi.insert({ age, name });
	}

	for (auto data : multi)
		std::cout << data.first << " " << data.second << "\n";

	return 0;
}



