#include<iostream>
#include<string>

void split()
{

}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::string front, back;

	std::cin >> n;
	std::cin.ignore();
	std::getline(std::cin, front, '*');
	std::getline(std::cin, back);


	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		int fSize, bSize, inputSize;

		if (front.size() + back.size() <= input.size())
		{
			if (front == input.substr(0, front.size()))
			{
				if (back == input.substr(input.size() - back.size()))
				{
					std::cout << "DA\n";
					continue;
				}
			}
		}

		std::cout << "NE\n";
	}


	return 0;
}

