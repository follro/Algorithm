#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(NULL);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<std::vector<std::string>> players('z' - 'a' + 1);

	int num;
	std::string input;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::cin >> input;
		players[input[0] - 'a'].push_back(input);
	}


	bool trigger = false;
	for (int i = 0; i <= 'z' - 'a' ; i++)
	{
		if (players[i].size() >= 5)
		{
			std::cout << (char)(i + 'a');
			trigger = true;
		}
	}

	if (trigger == false) std::cout << "PREDAJA";

}

