#include <iostream>

int x;
int stick = 1 << 6; 
int cnt;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> x;

	for (int i = 0; i <= 6; i++)
	{
		if (x & (1 << i))
			cnt++;
	}

	std::cout << cnt;

}