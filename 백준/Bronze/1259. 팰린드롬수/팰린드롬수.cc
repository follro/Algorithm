#include <iostream>
#include <string>
#include <vector>

int main()
{
	int input, i;

	while (1)
	{
		std::cin >> input;
		if (input == 0) break;

		std::string sInput = std::to_string(input);
		
		for (i = 0; i < sInput.size() / 2; i++)
		{
			if (sInput[i] != sInput[sInput.size() - 1 - i])
			{
				std::cout << "no\n";
				break;
			}

			
		}
		if (i == sInput.size() / 2)
			std::cout << "yes\n";
		
	}
	return 0;
}