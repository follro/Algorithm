#include<iostream>
#include<string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	int curNum = 666;
	std::cin >> n;

	while (n != 0)
		if (std::to_string(curNum++).find("666")!= std::string::npos) n--;
	

	std::cout << curNum - 1;

}