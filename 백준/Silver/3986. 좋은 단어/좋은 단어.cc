#include<iostream>
#include<stack>
#include<string>
int main()
{
	std::ios_base::sync_with_stdio(NULL);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, count = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string input;
		std::cin >> input;

		std::stack<char> table;
		
		for (char a : input)
		{
			if(!table.empty() && table.top() == a)
				table.pop();
			else
				table.push(a);
		}
		
		if (table.empty())
			count++;

	}

	std::cout << count;
	return 0;
}

