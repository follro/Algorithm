	#include <iostream>
	#include <string>
	#include <algorithm>

	int main()
	{
		//std::ios_base::sync_with_stdio(false);
		//std::cin.tie(NULL);
	
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
	
		std::string input, s;

		std::cin >> input;
		
		s = input;

		reverse(input.begin(), input.end());

		if (s == input) std::cout << "1";
		else
			std::cout << "0";

		return 0;
	}

