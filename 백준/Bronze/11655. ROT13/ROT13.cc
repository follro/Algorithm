#include<iostream>
#include<string>

int main()
{
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(NULL);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string input;

	std::getline(std::cin, input);
	std::cin;

	for (char& a : input)
	{
		if(a >= 'a' && a <= 'z')
		{
			if (a + 13 > 'z') a -= 13;
			else a += 13;
		}
		else if(a >= 'A' && a <= 'Z')
		{
			if (a + 13 > 'Z') a -= 13;
			else a += 13;
		}
		
	}

	std::cout << input;


}


