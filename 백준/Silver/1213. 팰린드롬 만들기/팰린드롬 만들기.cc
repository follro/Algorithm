#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::string name;
	std::vector<int> counting(26, 0);

	std::cin >> name;

	for (char a : name)
		counting[a - 65]++;
	
	int countIndex = -1;

	for (int i = 0; i < 26; i++)
	{
		if (counting[i] % 2 == 1)
		{
			if (countIndex >= 0)
			{
				std::cout << "I'm Sorry Hansoo";
				return 0;
			}
			countIndex = i;
		}
	}

	std::string result;
	std::string result2;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < counting[i] / 2; j++)
			result += i + 65;
	}

	result2 = result;
	std::reverse(result2.begin(), result2.end());
	if(countIndex != -1) result += countIndex + 65;
    
	std::cout << result + result2;
	
	return 0;
}

