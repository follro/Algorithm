#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int n;
std::vector <std::string> result;

bool cmp(const std::string& a , const std::string& b)
{
	if (a.length() == b.length())
		return a < b;

	return a.length() < b.length();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::string input;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		std::string num = "";

		for (auto c : input)
		{
			if (c >= '0' && c <= '9')
			{
				if (num == "0" && c == '0') continue;
				num += c;
			}
			else
			{
				if (num != "") result.push_back(num);
				num = "";
			}
		}

		if (num != "") result.push_back(num);
	}

	for (auto& s : result)
	{
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (*it != '0')
			{
				s = std::string(it, s.end());
				break;
			}
		}
	}

	std::sort(result.begin(), result.end(), cmp);

	for (auto s : result)
		std::cout << s << "\n";

}