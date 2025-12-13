#include<iostream>
#include<string>
#include<stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	
	
	std::string input;

	while (true)
	{
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] == '.') 
			break; 
		
		std::stack<char> s;
		bool checker = true;

		for (char c : input)
		{
			if (c == '[' || c == '(') s.push(c);
			else if (c == ']' || c == ')') {
				char e = (c == ']') ? '[' : '(';
				if (s.empty() || s.top() != e)
				{
					checker = false;
					break;
				}
				s.pop();
			}
		}

		if (checker && s.empty()) std::cout << "yes\n";
		else std::cout << "no\n";
	}

	return 0;
}